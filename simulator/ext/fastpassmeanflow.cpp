#include "fastpassmeanflow.h"

#include "fastpassflow.h"
#include "../coresim/packet.h"
#include "../coresim/topology.h"
#include "../coresim/event.h"

#include "fastpassTopology.h"

FastpassMeanFlow::FastpassMeanFlow(
		uint32_t mean_flow_size,
        uint32_t id,
        double start_time,
        uint32_t size,
        Host *s,
        Host *d
        ) : FastpassFlow(id, start_time, size, s, d) {
	this->predicted_flow_size = mean_flow_size;
    this->mean_flow_size = mean_flow_size;
    this->estimated_flow_size_packets = mean_flow_size / mss;
}

int FastpassMeanFlow::remaining_flow_size_estimate() {
	int current_packets_sent = size_in_pkt - sender_remaining_num_pkts;
	//this->total_pkt_sent
	//while(current_packets_sent >= estimated_flow_size_packets && size_in_pkt>estimated_flow_size_packets){
	while(current_packets_sent >= estimated_flow_size_packets){
		this->estimated_flow_size_packets = (this->estimated_flow_size_packets + 1) * 2;
	}
	int remaining_estimate = (estimated_flow_size_packets - current_packets_sent) + 1;
	return remaining_estimate;
}

void FastpassMeanFlow::send_data_pkt(){
	if(this->size_in_pkt - this->sender_remaining_num_pkts>=this->estimated_flow_size_packets){
		this->update_remaining_size();
		FastpassFlow::send_data_pkt();
	}else{
		FastpassFlow::send_data_pkt();
	}
}
