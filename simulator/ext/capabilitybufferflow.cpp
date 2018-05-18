#include "capabilitybufferflow.h"
#include <iostream>
#include <math.h>
#include "../run/params.h"

extern DCExpParams params;

CapabilityBufferFlow::CapabilityBufferFlow(
	uint32_t mean_flow_size,uint32_t id, double start_time, uint32_t size, Host *s, Host *d
): CapabilityFlow(id, start_time, size, s, d) {
    this->mean_flow_size = mean_flow_size;
    if(params.prediction_improvement != 0){
		this->mean_flow_size = ((double)size - mean_flow_size)*params.prediction_improvement + mean_flow_size;
		this->mean_flow_size = std::max(1., this->mean_flow_size);
	}
    this->buffer_size_in_packets = int(params.host_buffer_size) / mss;
        this->mean_flow_size_pkt = 1 +
        		(size_in_pkt>buffer_size_in_packets?buffer_size_in_packets:size_in_pkt);

    this->capability_goal = (int)(ceil(this->mean_flow_size_pkt * 1.00));
    this->remaining_pkts_at_sender = this->mean_flow_size_pkt;

    this->predicted_flow_size = mean_flow_size;
}

int CapabilityBufferFlow::remaining_pkts(){
	int remaining = size_in_pkt-received_count;
	while((mean_flow_size_pkt)<received_count){
		//std::cerr<<mean_flow_size_pkt<<std::endl;
		this->mean_flow_size_pkt += 1 +
					(remaining>buffer_size_in_packets?buffer_size_in_packets:remaining);
		this->capability_goal = (int)(ceil(this->mean_flow_size_pkt * 1.00));
		this->remaining_pkts_at_sender = this->mean_flow_size_pkt;
	}
	return std::max(0, (int)(mean_flow_size_pkt - received_count));
}
