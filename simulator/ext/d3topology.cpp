#include "d3topology.h"
#include <typeinfo>
#include <string>

extern double get_current_time();

D3SwitchInfo::D3SwitchInfo(double band){
	current_allocation = 0;
	current_demand = 0;
	time_measured = -1;
	current_bandwidth = band;
	data_sent = 0;
}

D3Topology::D3Topology(
        uint32_t num_hosts,
        uint32_t num_agg_switches,
        uint32_t num_core_switches,
        double bandwidth,
        uint32_t queue_type
        ) : PFabricTopology (num_hosts, num_agg_switches, num_core_switches, bandwidth, queue_type) {
	absolute_bandwidth = bandwidth;
}


Queue *D3Topology::get_next_hop(Packet *p, Queue *q) {
	process_packet(p, q);
    if (q->dst->type == HOST) {
        return NULL; // Packet Arrival
    }
    Queue * result;
    // At host level
    if (q->src->type == HOST) { // Same Rack or not
        assert (p->src->id == q->src->id);

        if (p->src->id / 16 == p->dst->id / 16) {
        	result = ((Switch *) q->dst)->queues[p->dst->id % 16];
        }
        else {
            uint32_t hash_port = 0;
            if(params.load_balancing == 0)
                hash_port = q->spray_counter++%4;
            else if(params.load_balancing == 1)
                hash_port = (p->src->id + p->dst->id + p->flow->id) % 4;
            result = ((Switch *) q->dst)->queues[16 + hash_port];
        }
    }

    // At switch level
    if (q->src->type == SWITCH) {
    	//process_packet(q->src->id, p);
        if (((Switch *) q->src)->switch_type == AGG_SWITCH) {
        	result = ((Switch *) q->dst)->queues[p->dst->id / 16];
        }
        if (((Switch *) q->src)->switch_type == CORE_SWITCH) {
        	result = ((Switch *) q->dst)->queues[p->dst->id % 16];
        }
    }

    //uint32_t dest_queue_id = ((Switch*)result->src)->id*10000+result->id;
    //process_packet(dest_queue_id, p, result->src);
    return result;
}

void D3Topology::process_packet(Packet* p, Queue* queue){
	Flow * flow = p->flow;
	uintptr_t queue_id = (uintptr_t)queue;

	if(allocation.find(queue_id)==allocation.end()){
		allocation[queue_id] = new D3SwitchInfo(absolute_bandwidth);
	}
	D3SwitchInfo* switch_info = allocation[queue_id];

	D3Packet* d3packet = nullptr;
	D3PacketAck* d3packetAck = nullptr;
	if (p->type == ACK_PACKET) {
		d3packetAck = (D3PacketAck*)p;
	}
	else if(p->type == NORMAL_PACKET) {
		d3packet = (D3Packet*)p;
	}

	//refine the bandwidth
	double ct = get_current_time();
	if(switch_info->time_measured==-1){
		switch_info->time_measured = ct;
	}else if(ct - switch_info->time_measured > time_delta){
		double delta = (ct - switch_info->time_measured);
		switch_info->time_measured = ct;
		switch_info->current_bandwidth =
			switch_info->current_bandwidth
			+ alpha*(switch_info->current_bandwidth-switch_info->data_sent/delta)
			- beta*(queue->bytes_in_queue/delta)
		;
		switch_info->current_bandwidth = std::min(switch_info->current_bandwidth, absolute_bandwidth);
		switch_info->current_bandwidth = std::max(switch_info->current_bandwidth, absolute_bandwidth/3);
		switch_info->data_sent = 0;
	}
	switch_info->data_sent += p->size*8;

	if(d3packet != nullptr){
		//if this flow is not finished
		if(d3packet->rate_request &&
			switch_info->finished_flows.find(flow->id) == switch_info->finished_flows.end()
		){
			//the flow starts
			if(d3packet->seq_no == 0){
				if(switch_info->flows.find(flow->id) == switch_info->flows.end()){
					switch_info->flows.insert(flow->id);
					port_mapping[std::make_pair(flow->id,(uintptr_t)queue->src)] = queue_id;
				}
			}
			//if there is a request, decide on the rate
			double old_demand = 0;
			double old_allocation = 0;

			//if this is not the first time we see the flow
			if(switch_info->demand.find(flow->id)!=switch_info->demand.end()){
				old_demand = switch_info->demand[flow->id];
				old_allocation = switch_info->allocation[flow->id];
			}

			int number_of_flows = std::max(1,(int)switch_info->flows.size());
			double new_demand = d3packet->desired_rate;
			switch_info->current_demand += -old_demand + new_demand;
			switch_info->current_allocation += -old_allocation;
			double left_capacity = switch_info->current_bandwidth - switch_info->current_allocation;
			//std::cerr<<switch_info->current_bandwidth<<" " << switch_info->current_allocation<<" "<<left_capacity<<std::endl;
			double fs = (switch_info->current_bandwidth - switch_info->current_demand)/number_of_flows;
			double new_allocation = base_rate;

			if(left_capacity > new_demand){
				new_allocation = new_demand+fs;
			}else{
				new_allocation = left_capacity;
			}

			new_allocation = new_allocation>base_rate?new_allocation:base_rate;

			switch_info->current_allocation += new_allocation;
			d3packet->new_allocation.push_back(new_allocation);

			switch_info->demand[flow->id] = new_demand;
			switch_info->allocation[flow->id] = new_allocation;
			//std::cerr<<"REQ "<<flow->id<<" "<<(uintptr_t)queue->src<<" "<<switch_info->current_allocation<<"\n";
		}
		return;
	}else if(d3packetAck != nullptr){// && switch_info->flows.find(flow->id)!=switch_info->flows.end()){
		// when it finishes, it should decrease
		std::pair<int, uintptr_t> flow_key = std::make_pair(flow->id,(uintptr_t)queue->dst);

		switch_info = allocation[port_mapping[flow_key]];
		if(switch_info!=NULL){
			double old_allocation = switch_info->allocation[flow->id];
			if(d3packetAck->last_packet){
				double old_demand = switch_info->demand[flow->id];

				switch_info->finished_flows.insert(flow->id);
				switch_info->flows.erase(flow->id);
				switch_info->demand.erase(flow->id);
				switch_info->allocation.erase(flow->id);
				switch_info->current_allocation -= old_allocation;
				switch_info->current_demand -= old_demand;
				switch_info->current_allocation = std::max(0.,switch_info->current_allocation);
				switch_info->current_demand = std::max(0.,switch_info->current_demand);
				port_mapping.erase(flow_key);
				//std::cerr<<"RES "<<flow->id<<" "<<(uintptr_t)queue->dst<<" "<<switch_info->current_demand<<"\n";
			} else if(d3packetAck->allocated_rate!=-1){
				switch_info->allocation[flow->id] = d3packetAck->allocated_rate;
				switch_info->current_allocation += - old_allocation + d3packetAck->allocated_rate;
			}
		}

		return;
	}
}

