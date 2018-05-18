#ifndef PFABRIC_OPTIMIZED_FLOW_H
#define PFABRIC_OPTIMIZED_FLOW_H

#include "pfabricflow.h"
#include "../coresim/node.h"

class PFabricOptimizedFlow : public PFabricFlow {
    public:
	PFabricOptimizedFlow(uint32_t prediction, uint32_t id, double start_time, uint32_t size, Host *s, Host *d);
        double predicted_size;
        virtual uint32_t get_priority(uint32_t seq);
};

#endif
