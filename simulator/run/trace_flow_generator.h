
#ifndef TRACE_FLOW_GEN_H
#define TRACE_FLOW_GEN_H

#include "flow_generator.h"

#include <iostream>
#include <vector>
using namespace std;

extern DCExpParams params;

class TraceFlowGenerator : public FlowGenerator {
protected:
	vector<vector<vector<double>>> traces;
	vector<vector<uint32_t>> destinations;
	bool use_probabilities = false;

	vector<double> centers;

	void schedule_one_flow(double current_moment);
	void read_traces();
	void read_trace(string trace_path);
	vector<double> parse_line(string line);
public:
	TraceFlowGenerator(uint32_t num_flows, Topology *topo, std::string filename);
    virtual void make_flows();

};

#endif
