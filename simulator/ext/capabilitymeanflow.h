#ifndef CAPABILITY_MEAN_FLOW_H
#define CAPABILITY_MEAN_FLOW_H

#include "capabilityflow.h"

class CapabilityMeanFlow : public CapabilityFlow {
public:
	CapabilityMeanFlow(uint32_t mean_flow_size, uint32_t id, double start_time, uint32_t size, Host *s, Host *d);
	double mean_flow_size;
	double mean_flow_size_pkt;
	int remaining_pkts();
};


#endif

