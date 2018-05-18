#include "pfabricbuffer.h"
#include <iostream>
#include <algorithm>
#include "../run/params.h"

extern DCExpParams params;

PFabricBufferFlow::PFabricBufferFlow(
		uint32_t id, double start_time, uint32_t size, Host *s, Host *d
) : PFabricFlow(id, start_time, size, s, d) {

}

uint32_t PFabricBufferFlow::get_priority(uint32_t seq) {
	uint32_t buffer_size = params.host_buffer_size;
	uint32_t currently_sent = last_unacked_seq + scoreboard_sack_bytes;
	double remaining = size-currently_sent;
	if(remaining>buffer_size){
		return buffer_size;
	}else{
		return remaining;
	}
}
