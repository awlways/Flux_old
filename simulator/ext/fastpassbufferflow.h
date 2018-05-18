#ifndef FASTPASS_BUFFER_FLOW_H
#define FASTPASS_BUFFER_FLOW_H

#include "fastpassflow.h"

class FastpassBufferFlow : public FastpassFlow {
public:
	FastpassBufferFlow(uint32_t mean_flow_size, uint32_t id, double start_time, uint32_t size, Host *s, Host *d);
	double mean_flow_size;
	double estimated_flow_size_packets;
	double buffer_size_in_packets;
	int remaining_flow_size_estimate();
	void send_data_pkt();
};

#endif
