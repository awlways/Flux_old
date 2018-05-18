#include "fastpassbufferflow.h"

#include "fastpassflow.h"
#include "../coresim/packet.h"
#include "../coresim/topology.h"
#include "../coresim/event.h"

#include "fastpassTopology.h"

FastpassBufferFlow::FastpassBufferFlow(
		uint32_t mean_flow_size,
        uint32_t id,
        double start_time,
        uint32_t size,
        Host *s,
        Host *d
        ) : FastpassFlow(id, start_time, size, s, d) {
	this->predicted_flow_size = mean_flow_size;
    this->mean_flow_size = mean_flow_size;

    this->buffer_size_in_packets = int(params.host_buffer_size) / mss;
    this->estimated_flow_size_packets = 1 +
    		(sender_remaining_num_pkts>buffer_size_in_packets?buffer_size_in_packets:sender_remaining_num_pkts);
}

int FastpassBufferFlow::remaining_flow_size_estimate() {
	int current_packets_sent = size_in_pkt - sender_remaining_num_pkts;

	while(current_packets_sent >= estimated_flow_size_packets){
		this->estimated_flow_size_packets += 1 +
				(sender_remaining_num_pkts>buffer_size_in_packets?buffer_size_in_packets:sender_remaining_num_pkts);
	}
	int remaining_estimate = (estimated_flow_size_packets - current_packets_sent) + 1;
	return remaining_estimate;


//	int remaining = 1 + sender_remaining_num_pkts>buffer_size_in_packets?buffer_size_in_packets:sender_remaining_num_pkts;
//	this->estimated_flow_size_packets += remaining;
//	return remaining;


}

void FastpassBufferFlow::send_data_pkt(){
	if(this->size_in_pkt - this->sender_remaining_num_pkts>=this->estimated_flow_size_packets){
		this->update_remaining_size();
	}else{
		FastpassFlow::send_data_pkt();
	}
}
