#include "pfabricthresholdperfect.h"
#include <iostream>
#include <algorithm>
#include "../run/params.h"

extern DCExpParams params;

PFabricThresholdPerfectFlow::PFabricThresholdPerfectFlow(
	std::vector<double> thresholds, uint32_t id, double start_time, uint32_t size, Host *s, Host *d
) : PFabricFlow(id, start_time, size, s, d) {
	this->thresholds = thresholds;

	//set threshold
	if(size>=thresholds.back()){
		current_threshold =thresholds.back()+1;
	}else{
		current_threshold = thresholds.front();
		while(size>=current_threshold){
			thresholds.erase(thresholds.begin());
			current_threshold = thresholds.front();
		}
	}
}

uint32_t PFabricThresholdPerfectFlow::get_priority(uint32_t seq) {
	return current_threshold;
}
