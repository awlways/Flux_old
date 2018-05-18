#include "pfabricoptimizedflow.h"
#include <iostream>
#include "../run/params.h"

extern DCExpParams params;

PFabricOptimizedFlow::PFabricOptimizedFlow(
    uint32_t prediction, uint32_t id, double start_time, uint32_t size, Host *s, Host *d
) : PFabricFlow(id, start_time, size, s, d) {
    this->predicted_size = prediction;
    if(size<params.host_buffer_size){
    	this->predicted_size = size;
    } else if (this->predicted_size<params.host_buffer_size){
    	this->predicted_size = params.host_buffer_size + 1;
    }
}

uint32_t PFabricOptimizedFlow::get_priority(uint32_t seq) {
	while((predicted_size - seq)<0){
		predicted_size = (predicted_size+1)*1.1;
	}
	uint32_t result = predicted_size;
    return result>1?result:1;
}
