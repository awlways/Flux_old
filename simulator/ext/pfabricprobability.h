#ifndef PFABRIC_PROBABILITY_FLOW_H
#define PFABRIC_PROBABILITY_FLOW_H

#include "pfabricflow.h"
#include "../coresim/node.h"
#include <vector>

class PFabricProbabilityFlow : public PFabricFlow {
    public:
		PFabricProbabilityFlow(std::vector<double> probabilities, std::vector<double> centers,
        		uint32_t id, double start_time, uint32_t size, Host *s, Host *d);
		void set_prediction(std::vector<double>& probabilities, std::vector<double>& centers);
        virtual uint32_t get_priority(uint32_t seq);
        std::vector<double> probabilities;
        std::vector<double> centers;
        double current_flow_prediction;
};

#endif
