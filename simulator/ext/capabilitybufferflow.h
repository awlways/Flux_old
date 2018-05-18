#ifndef CAPABILITY_BUFFER_FLOW_H
#define CAPABILITY_BUFFER_FLOW_H

#include "capabilityflow.h"

class CapabilityBufferFlow : public CapabilityFlow {
public:
	CapabilityBufferFlow(uint32_t mean_flow_size, uint32_t id, double start_time, uint32_t size, Host *s, Host *d);
	double mean_flow_size;
	double mean_flow_size_pkt;
	int buffer_size_in_packets;
	int remaining_pkts();
};


#endif

