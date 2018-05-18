
#include "pfabricseq.h"
#include <iostream>
#include <algorithm>
#include "../run/params.h"

extern DCExpParams params;

PFabricSeqFlow::PFabricSeqFlow(
		uint32_t id, double start_time, uint32_t size, Host *s, Host *d
) : PFabricFlow(id, start_time, size, s, d) {

}

uint32_t PFabricSeqFlow::get_priority(uint32_t seq) {
//	uint32_t limit = params.thresholds.front();
//	if(seq < limit){
//		return limit;
//	}else{
//		return limit+1;
//	}
	return seq;
}
