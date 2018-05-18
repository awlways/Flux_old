#ifndef PFABRIC_BUFFER_FLOW_H
#define PFABRIC_BUFFER_FLOW_H

#include "pfabricflow.h"
#include "../coresim/node.h"
#include <vector>

class PFabricBufferFlow : public PFabricFlow {
    public:
		PFabricBufferFlow(uint32_t id, double start_time, uint32_t size, Host *s, Host *d);
        virtual uint32_t get_priority(uint32_t seq);
};

#endif
