
#ifndef TRACE_CDF_GEN_H
#define TRACE_CDF_GEN_H

#include "trace_flow_generator.h"
#include "../coresim/event.h"
#include <iostream>
#include <vector>
using namespace std;

extern DCExpParams params;

class TraceCDFGenerator : public TraceFlowGenerator {
protected:
	vector<vector<uint32_t>> flow_size_prediction;
    double meanFlowSize;
    void flattenTrace();
public:
	TraceCDFGenerator(uint32_t num_flows, Topology *topo, std::string filename);
    virtual void make_flows();
};


class TraceRandomVariable{
protected:
    vector<vector<uint32_t>>* flow_size_prediction;
    long long numberOfFlows;
public:
  virtual vector<uint32_t> value();
  TraceRandomVariable(vector<vector<uint32_t>>* p_flow_size_prediction);
};

//A flow arrival event Only used for FlowCreation
class TraceFlowCreationForInitializationEvent : public Event {
    public:
        TraceFlowCreationForInitializationEvent(
                double time, 
                Host *src, 
                Host *dst,
                TraceRandomVariable *nv_bytes,
                ExponentialRandomVariable *nv_intarr
                );
        ~TraceFlowCreationForInitializationEvent();
        void process_event();
        Host *src;
        Host *dst;
        TraceRandomVariable *nv_bytes;
        ExponentialRandomVariable *nv_intarr;
};

#endif
