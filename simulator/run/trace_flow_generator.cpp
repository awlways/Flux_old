#include "trace_flow_generator.h"
#include "../coresim/random_variable.h"

#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <map>
#include "params.h"

extern DCExpParams params;
void removeCharsFromString( string &str, char* charsToRemove );

TraceFlowGenerator::TraceFlowGenerator(
	uint32_t num_flows,
	Topology *topo,
	std::string filename)
:FlowGenerator(num_flows, topo, filename){

}

void TraceFlowGenerator::make_flows(){
	srand(1);
	read_traces();

	// Statistics tracking
	double time = 1;

	int generated_cases = 0;
	//while (time <= 1.3) {
	while (generated_cases < params.num_flows_to_run) {
		// Poisson arrival
		int r = rand()-1;
		r = r>0?r:1;
		double interArrivalTime = (-log(r/double(RAND_MAX))) / (200);
		// Advance time to next arrival
		time += interArrivalTime;
		// Add to sum for later statistics
		schedule_one_flow(time);
		//std::cerr<<r/double(RAND_MAX)<<time<<std::endl;
		generated_cases++;
	}
	current_time = 0;
	params.num_flows_to_run = flows_to_schedule.size();

}

void TraceFlowGenerator::schedule_one_flow(double current_moment){
	int trace_index = rand() % traces.size();
	int src_index = (rand() % topo->hosts.size()) % params.number_of_hosts;

	vector<vector<double>> trace = traces[trace_index];
	vector<uint32_t> destination = destinations[trace_index];

	map<uint32_t, uint32_t> dst_mapping;
	set<uint32_t> real_destinations;

	while(real_destinations.size()<destination.size()){
		int dst_ind = (rand() % topo->hosts.size()) % params.number_of_hosts;
		uint32_t div = params.number_of_hosts<=(params.num_hosts/params.num_agg_switches)?
				1:(params.num_hosts/params.num_agg_switches);
		if(dst_ind/div != src_index/div){
			real_destinations.insert(dst_ind);
		}
	}
	vector<uint32_t> vreal_destinations;
	vreal_destinations.assign(real_destinations.begin(), real_destinations.end());
	for(int i = 0; i < destination.size(); i++){
		dst_mapping[destination[i]] = vreal_destinations[i];
	}

	int n_o_t = 1000;
	int upperLimit = trace.size()>n_o_t?n_o_t:trace.size();
//	int upperLimit = trace.size();
	for (int i = 0; i < upperLimit; i++) {
		vector<double> flow = trace[i];
		uint32_t id = flows_to_schedule.size();
		uint32_t dst_index = dst_mapping[flow[2]];

		if(use_probabilities){
			vector<double> prob(flow.begin()+4, flow.begin()+4+centers.size());
			flows_to_schedule.push_back(
				Factory::get_flow(
					current_moment + flow[1]/double(params.squeezing_factor),
					flow[3],
					topo->hosts[src_index],//topo->hosts[(rand() % topo->hosts.size()) % params.number_of_hosts],
					topo->hosts[dst_index],//topo->hosts[(rand() % topo->hosts.size()) % params.number_of_hosts],
					params.flow_type,
					0.,
					flow[3],
					&prob,
					&centers
				)
			);
		} else {
			/*std::cout
				<<current_moment + flow[1]/double(params.squeezing_factor)<<" "
				<<flow[3]<<" "
				<<topo->hosts[src_index]<<" "
				<<topo->hosts[dst_index]<<" "
				<<flow[4]<<" "
				<<std::endl;*/
			flows_to_schedule.push_back(
				Factory::get_flow(
					current_moment + flow[1]/double(params.squeezing_factor),
//					trace[rand() % topo->hosts.size()][3],
					flow[3],
//					topo->hosts[(rand() % topo->hosts.size()) % params.number_of_hosts],
//					topo->hosts[(rand() % topo->hosts.size()) % params.number_of_hosts],
					topo->hosts[src_index],
					topo->hosts[dst_index],
					params.flow_type,
					0.,
					flow[4]
				)
			);
		}
	}
}

void TraceFlowGenerator::read_traces(){
	traces = vector<vector<vector<double>>>();
	DIR *dpdf;
	struct dirent *epdf;

	dpdf = opendir(filename.c_str());

	if (dpdf != NULL){
	   while (epdf = readdir(dpdf)){
		  if(strlen(epdf->d_name)>5){
			  read_trace(filename + epdf->d_name);
		  }
	   }
	}
	closedir(dpdf);
}

void TraceFlowGenerator::read_trace(string trace_path){
	vector<vector<double>> trace;
	vector<uint32_t> destination;

	ifstream input(trace_path);
	string line;

	//skip first line
	getline(input, line);

	if(line.find('--')==0){
		use_probabilities=true;
		centers = parse_line(line.substr(2));
		//skip one more line
		getline(input, line);
	}

	while (getline(input, line)) {

		vector<double> flow = parse_line(line);
		trace.push_back(flow);

		//add destination
		if(std::find(destination.begin(), destination.end(), flow[2]) == destination.end()) {
			destination.push_back(flow[2]);
		}
	}
	traces.push_back(trace);
	destinations.push_back(destination);
}

vector<double> TraceFlowGenerator::parse_line(string line){
    vector<double> list;
    size_t pos = 0;
    string token;
    double value;
    while ((pos = line.find(",")) != string::npos) {
        token = line.substr(0, pos);
        if(use_probabilities)removeCharsFromString(token, "\"");
        value = atof(token.c_str());
        list.push_back(
        	value
        );
        line.erase(0, pos + 1);
    }

    //take the last element
    if(use_probabilities)removeCharsFromString(line, "\"");
	value = atof(line.c_str());
	list.push_back(
		value
	);
    return list;
}

void removeCharsFromString( string &str, char* charsToRemove ) {
   for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
      str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
   }
}
