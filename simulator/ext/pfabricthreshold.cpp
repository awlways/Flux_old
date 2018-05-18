#include "pfabricthreshold.h"
#include <iostream>
#include <algorithm>
#include "../run/params.h"

extern DCExpParams params;

PFabricThresholdFlow::PFabricThresholdFlow(
	std::vector<double> thresholds, uint32_t id, double start_time, uint32_t size, Host *s, Host *d
) : PFabricFlow(id, start_time, size, s, d) {
	this->thresholds = thresholds;
	this->current_threshold = thresholds.front();
}

uint32_t PFabricThresholdFlow::get_priority(uint32_t seq) {
	if(seq>=current_threshold && thresholds.size()!=0){
		thresholds.erase(thresholds.begin());
		if(thresholds.size()>0){
			current_threshold = thresholds.front();
		}else {
			current_threshold++;
		}
	}
	return current_threshold;
}
