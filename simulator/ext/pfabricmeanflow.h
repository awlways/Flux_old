#ifndef PFABRIC_MEAN_FLOW_H
#define PFABRIC_MEAN_FLOW_H

#include "pfabricflow.h"
#include "../coresim/node.h"

class PFabricMeanFlow : public PFabricFlow {
    public:
        PFabricMeanFlow(uint32_t mean_flow_size, uint32_t id, double start_time, uint32_t size, Host *s, Host *d);
        double mean_flow_size;
        virtual uint32_t get_priority(uint32_t seq);
};

#endif
