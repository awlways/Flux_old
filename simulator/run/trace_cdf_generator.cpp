#include "trace_cdf_generator.h"

#include <cstdint>
#include <cstdlib>
#include <deque>
#include <queue>
#include <string>
#include <iostream>

#include "../coresim/random_variable.h"
#include "../coresim/topology.h"
#include "../ext/factory.h"
#include "flow_generator.h"
#include "params.h"

extern DCExpParams params;

TraceRandomVariable::TraceRandomVariable(vector<vector<uint32_t>>* p_flow_size_prediction){
    flow_size_prediction = p_flow_size_prediction;
    numberOfFlows = (*flow_size_prediction).size();
}

vector<uint32_t> TraceRandomVariable::value() { // never return 0
  long long index = rand()%numberOfFlows;
  return (*flow_size_prediction)[index];
}

TraceCDFGenerator::TraceCDFGenerator(
	uint32_t num_flows,
	Topology *topo,
	std::string filename)
:TraceFlowGenerator(num_flows, topo, filename){
    read_traces();
    flattenTrace();
}

void TraceCDFGenerator::flattenTrace(){
    double totalData = 0;
    for(int i = 0; i < traces.size(); i++){
        for(int j = 0; j < traces[i].size(); j++){
            vector<uint32_t> flow;
            //real size
            flow.push_back(traces[i][j][3]);
            totalData += traces[i][j][3];
            //prediction
            flow.push_back(traces[i][j][4]);

            flow_size_prediction.push_back(flow);
        }
    }
    meanFlowSize = totalData / flow_size_prediction.size();
}

void TraceCDFGenerator::make_flows(){
	srand(1);

    TraceRandomVariable *nv_bytes;
    nv_bytes = new TraceRandomVariable(&flow_size_prediction);

    params.mean_flow_size = meanFlowSize;
//  std::cout<<params.mean_flow_size<<"\n";

    double lambda = params.bandwidth * params.load / (params.mean_flow_size * 8. / 1460. * 1500.);
    double lambda_per_host = lambda / (topo->hosts.size() - 1);

    ExponentialRandomVariable *nv_intarr;
    nv_intarr = new ExponentialRandomVariable(1.0 / lambda_per_host);

    for (uint32_t i = 0; i < topo->hosts.size(); i++) {
        for (uint32_t j = 0; j < topo->hosts.size(); j++) {
            if (i != j) {
                double first_flow_time = 1.0 + nv_intarr->value();
                add_to_event_queue(
                    new TraceFlowCreationForInitializationEvent(
                        first_flow_time,
                        topo->hosts[i], 
                        topo->hosts[j],
                        nv_bytes, 
                        nv_intarr
                    )
                );
            }
        }
    }

    while (event_queue.size() > 0) {
        Event *ev = event_queue.top();
        event_queue.pop();
        current_time = ev->time;
        if (flows_to_schedule.size() < num_flows) {
            ev->process_event();
        }
        delete ev;
    }
    current_time = 0;
}


/* Flow Arrival */
TraceFlowCreationForInitializationEvent::TraceFlowCreationForInitializationEvent(
        double time, 
        Host *src, 
        Host *dst,
        TraceRandomVariable *nv_bytes, 
        ExponentialRandomVariable *nv_intarr
    ) : Event(FLOW_CREATION_EVENT, time) {
    this->src = src;
    this->dst = dst;
    this->nv_bytes = nv_bytes;
    this->nv_intarr = nv_intarr;
}

TraceFlowCreationForInitializationEvent::~TraceFlowCreationForInitializationEvent() {}

void TraceFlowCreationForInitializationEvent::process_event() {
    vector<uint32_t> flow;
    uint32_t size, prediction;
    uint32_t id = flows_to_schedule.size();    
    flow = nv_bytes->value();
    size = (uint32_t) flow[0];
    prediction = (uint32_t) flow[1];

    if (size != 0) {
        flows_to_schedule.push_back(Factory::get_flow(id, time, size, src, dst, params.flow_type, 0, prediction));
    }

    double tnext = time + nv_intarr->value();

    add_to_event_queue(
            new TraceFlowCreationForInitializationEvent(
                tnext,
                src, 
                dst,
                nv_bytes, 
                nv_intarr
                )
            );
}
