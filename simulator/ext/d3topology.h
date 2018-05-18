#ifndef D3TOPOLOGY_H
#define D3TOPOLOGY_H

#include <map>
#include <set>

#include "../coresim/topology.h"
#include "d3flow.h"

class D3SwitchInfo {
public:
	double current_allocation;
	double current_demand;
	std::set<int> flows;
	std::set<int> finished_flows;
	std::map<int, double> demand;
	std::map<int, double> allocation;
	double time_measured;
	double current_bandwidth;
	double data_sent;

	D3SwitchInfo(double band);
	D3SwitchInfo(){};
};

class D3Topology: public PFabricTopology {
	void process_packet(Packet* p, Queue* queue);
public:
	D3Topology(uint32_t num_hosts, uint32_t num_agg_switches,
			uint32_t num_core_switches, double bandwidth, uint32_t queue_type);

	virtual Queue* get_next_hop(Packet *p, Queue *q);

	std::map<uintptr_t, D3SwitchInfo*> allocation;
	std::map<std::pair<int,uintptr_t>, uintptr_t> port_mapping;

	//10Mbps
	double base_rate = 100000;
	double absolute_bandwidth;

	double const time_delta = 0.0005;
	double const alpha = 0.1;
	double const beta = 1.;
};

#endif
