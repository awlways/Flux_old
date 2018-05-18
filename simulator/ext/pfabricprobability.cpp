#include "pfabricprobability.h"
#include <iostream>
#include <algorithm>
#include "../run/params.h"

extern DCExpParams params;

PFabricProbabilityFlow::PFabricProbabilityFlow(
		std::vector<double> probabilities, std::vector<double> centers, uint32_t id,
		double start_time, uint32_t size, Host *s, Host *d
) : PFabricFlow(id, start_time, size, s, d) {
	this->probabilities = probabilities;
	this->centers = centers;
	set_prediction(this->probabilities, this->centers);
}

uint32_t PFabricProbabilityFlow::get_priority(uint32_t seq) {
	while(current_flow_prediction < seq){
		set_prediction(this->probabilities, this->centers);
	}
    double result = current_flow_prediction - seq;
	//double result = current_flow_prediction;
    //if(current_flow_prediction<10000)std::cerr<<current_flow_prediction<<std::endl;
    return result>1?result:1;
}

void PFabricProbabilityFlow::set_prediction(std::vector<double>& probabilities, std::vector<double>& centers){
	if(probabilities.size()!=0){
		//find max probability
		std::vector<double>::iterator max_iter = std::max_element(probabilities.begin(), probabilities.end());
		double max_probability = *max_iter;
		int max_index = std::distance(probabilities.begin(), max_iter);
		std::vector<int> remove_list;

		//find elements to remove
		double current_center = centers[max_index];
		for(int i=0; i<centers.size(); i++){
			if(centers[i]<=centers[max_index]){
				remove_list.push_back(i);
			}
		}

		//remove elements
		for(int i=remove_list.size()-1; i>=0; i--){
			probabilities.erase(probabilities.begin()+remove_list[i]);
			centers.erase(centers.begin()+remove_list[i]);
		}

		if(probabilities.size()!=0){
			//std::cerr<<current_flow_prediction;
			double second_smallest = *std::min_element(centers.begin(), centers.end());
			current_flow_prediction = (current_center+second_smallest)/2;
			//std::cerr<<" "<<current_flow_prediction<<std::endl;
		} else{
			current_flow_prediction = current_center;
		}
	}else{
		current_flow_prediction = (current_flow_prediction+1)*2;
	}

	current_flow_prediction = std::max((double)mss,current_flow_prediction);
}
