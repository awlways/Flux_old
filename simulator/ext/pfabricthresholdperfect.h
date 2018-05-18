#ifndef PFABRIC_THRESHOLD_PERFECT_FLOW_H
#define PFABRIC_THRESHOLD_PERFECT_FLOW_H

#include "pfabricflow.h"
#include "../coresim/node.h"
#include <vector>

class PFabricThresholdPerfectFlow : public PFabricFlow {
    public:
	PFabricThresholdPerfectFlow(std::vector<double> thresholds, uint32_t id, double start_time, uint32_t size, Host *s, Host *d);
        virtual uint32_t get_priority(uint32_t seq);
        std::vector<double> thresholds;
        double current_threshold;
};

#endif
