#include "capabilitymeanflow.h"
#include <iostream>
#include <math.h>
#include "../run/params.h"

extern DCExpParams params;

CapabilityMeanFlow::CapabilityMeanFlow(
	uint32_t mean_flow_size,uint32_t id, double start_time, uint32_t size, Host *s, Host *d
): CapabilityFlow(id, start_time, size, s, d) {
    this->mean_flow_size = mean_flow_size;
    if(params.prediction_improvement != 0){
		this->mean_flow_size = ((double)size - mean_flow_size)*params.prediction_improvement + mean_flow_size;
		this->mean_flow_size = std::max(1., this->mean_flow_size);
	}
    mean_flow_size_pkt = (int)ceil((double)this->mean_flow_size/1460);
    this->capability_goal = (int)(ceil(this->mean_flow_size_pkt * 1.00));
    this->remaining_pkts_at_sender = this->mean_flow_size_pkt;

    this->predicted_flow_size = mean_flow_size;
}

int CapabilityMeanFlow::remaining_pkts(){
	//return std::max((int)0, (int)(this->size_in_pkt - this->received_count));
	while((mean_flow_size_pkt)<received_count){
		mean_flow_size_pkt = (mean_flow_size_pkt+1)*2;
		this->capability_goal = (int)(ceil(this->mean_flow_size_pkt * 1.00));
		this->remaining_pkts_at_sender = this->mean_flow_size_pkt;
	}
	return std::max(0, (int)(mean_flow_size_pkt - received_count));
}
