#ifndef D3_FLOW_H
#define D3_FLOW_H

#include "pfabricflow.h"
#include "../coresim/node.h"
#include "../coresim/packet.h"

#include <vector>

class D3Packet: public Packet {
    public:
		D3Packet(double sending_time, Flow *flow, uint32_t seq_no, uint32_t pf_priority,
                uint32_t size, Host *src, Host *dst, double desired_rate, bool rate_request);
		bool rate_request;
		double desired_rate;
		std::vector<double> new_allocation;
};

class D3PacketAck : public Ack {
    public:
		D3PacketAck(Flow *flow, uint32_t seq_no_acked, std::vector<uint32_t> sack_list,
                uint32_t size,
                Host* src, Host *dst, double allocated_rate, bool last_packet);
		double allocated_rate;
		bool last_packet;
};

class D3Flow : public PFabricFlow {
    public:
		D3Flow(uint32_t id, double start_time, uint32_t size, Host *s, Host *d, uint32_t predicted_flow_size,
				double deadline);
		void send_pending_data();
		Packet *send(uint32_t seq);
		void receive_data_pkt(Packet* p);
		void receive_ack(Ack* ack_packet, uint32_t ack, std::vector<uint32_t> sack_list);
		void increase_cwnd();
		void send_ack(Packet* received_packet, uint32_t seq, std::vector<uint32_t> sack_list);
		void handle_timeout();
		virtual uint32_t get_priority(uint32_t seq);

        uint32_t seq_measure_rtt = -1;
        bool send_rate_reuqst = true;
        double last_moment_request_sent = 0;
        //double remaining_flow_size = predicted_flow_size;
        double current_rate = 1;
        double rtt = 0.000001;
        uint32_t border;
        double remaining_deadline;
};

#endif
