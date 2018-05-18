#include "pfabricmeanflow.h"
#include <iostream>
#include "../run/params.h"

extern DCExpParams params;

PFabricMeanFlow::PFabricMeanFlow(
    uint32_t mean_flow_size, uint32_t id, double start_time, uint32_t size, Host *s, Host *d
) : PFabricFlow(id, start_time, size, s, d) {
    this->mean_flow_size = mean_flow_size;
    if(params.prediction_improvement != 0){
    	this->mean_flow_size = ((double)size - mean_flow_size)*params.prediction_improvement + mean_flow_size;
    }
    /*if(this->mean_flow_size<params.host_buffer_size){
    	this->mean_flow_size = size;
    }*/

    this->mean_flow_size = std::max(1., this->mean_flow_size);
}

uint32_t PFabricMeanFlow::get_priority(uint32_t seq) {
	uint32_t currently_sent = last_unacked_seq + scoreboard_sack_bytes;
	while(mean_flow_size < currently_sent){
		mean_flow_size = (mean_flow_size+1)*2;
	}
    double result = mean_flow_size - currently_sent;
    return result>1?result:1;
}
