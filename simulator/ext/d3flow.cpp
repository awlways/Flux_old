#include <coresim/event.h>
#include <coresim/topology.h>
#include <ext/d3flow.h>
#include <float.h>
#include <run/params.h>
#include <stddef.h>
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <cassert>

extern double get_current_time();
extern Topology* topology;
extern void add_to_event_queue(Event *);
extern int get_event_queue_size();
extern DCExpParams params;
extern std::priority_queue<Event*, std::vector<Event*>, EventComparator> event_queue;

D3Flow::D3Flow(uint32_t id, double start_time, uint32_t size, Host *s, Host *d,
		uint32_t predicted_flow_size, double deadline) :
		PFabricFlow(id, start_time, size, s, d) {
	this->predicted_flow_size = predicted_flow_size;
	this->remaining_deadline = this->deadline;
	//this->deadline = deadline;
}

D3Packet::D3Packet(double sending_time, Flow *flow, uint32_t seq_no,
		uint32_t pf_priority, uint32_t size, Host *src, Host *dst,
		double desired_rate, bool rate_request) :
		Packet(sending_time, flow, seq_no, pf_priority, size, src, dst) {
	this->desired_rate = desired_rate;
	this->rate_request = rate_request;
}

D3PacketAck::D3PacketAck(Flow *flow, uint32_t seq_no_acked,
		std::vector<uint32_t> sack_list, uint32_t size, Host* src, Host *dst,
		double allocated_rate, bool last_packet) :
		Ack(flow, seq_no_acked, sack_list, size, src, dst) {
	this->allocated_rate = allocated_rate;
	this->last_packet = last_packet;
}

void D3Flow::send_pending_data() {
	if (recv_till < size && !finished) {
		//last_unacked_seq
		border = next_seq_no;
		uint32_t seq = next_seq_no;
		uint32_t window = cwnd_mss + scoreboard_sack_bytes;
		while ((size > seq) && (seq < border + window) && !finished) {
			send(seq);
			if (seq + mss <= size) {
				uint32_t inc;
				if (seq + mss <= border + window) {
					inc = mss;
				} else {
					inc = border + window - seq;
				}
				next_seq_no = seq + inc;
				seq += inc;
			} else {
				next_seq_no = size;
				seq = size;
			}

			if (retx_event == NULL) {
				set_timeout(get_current_time() + retx_timeout);
			}
		}
	}
}

Packet *D3Flow::send(uint32_t seq) {
	//std::cerr<<"SEND "<<seq<<"\n";
	D3Packet *p = NULL;
	uint32_t pkt_size;
	//decide the size
	if (seq + mss > this->size) {
		pkt_size = this->size - seq + hdr_size;
	} else {
		uint32_t inc;
		if (seq + mss < border + cwnd_mss) {
			inc = mss;
		} else {
			inc = border + cwnd_mss - seq;
		}
		pkt_size = inc + hdr_size;
	}

	//flow size estimate
	while ((predicted_flow_size - last_unacked_seq - scoreboard_sack_bytes) <= 0) {
		predicted_flow_size = (predicted_flow_size+1)*2;
	}

	//estimate the rate
	double desired_rate = -1;
	if (send_rate_reuqst) {
		seq_measure_rtt = seq;
		last_moment_request_sent = get_current_time();
		send_rate_reuqst = false;

		if (remaining_deadline > 0) {
			double remaining_flow_size = predicted_flow_size - last_unacked_seq
					- scoreboard_sack_bytes;
			desired_rate = std::max(0.,
					(8 * remaining_flow_size - rtt * current_rate));
			desired_rate /= ((remaining_deadline));
			remaining_deadline = remaining_deadline - rtt;
		} else {
			desired_rate = 0;
		}
	}

	//std::cerr<<id<<" SEND PACKET "<< seq<<std::endl;
	//create and send the packet
	p = new D3Packet(get_current_time(), this, seq, seq == 0 ? 0 : 1, pkt_size,
			src, dst, desired_rate, desired_rate != -1);

	this->total_pkt_sent++;

	Event* e = new PacketQueuingEvent(get_current_time(), p, src->queue);
	e->additional_priority = event_queue.size();
	add_to_event_queue(e);
	return p;
}

void D3Flow::receive_ack(Ack* ack_packet, uint32_t ack,
		std::vector<uint32_t> sack_list) {
	//std::cerr<<ack_packet->total_queuing_delay<<std::endl;
	this->scoreboard_sack_bytes = sack_list.size() * mss;
	this->scoreboard_sack_bytes = 0;
	D3PacketAck* d3_ack_packet = (D3PacketAck*) ack_packet;

	//std::cerr<<id<<" RECEIVED ACK "<< ack<<std::endl;
//	if (next_seq_no < ack) {
//		next_seq_no = ack;
//	}

	// New ack!
	if (ack >= last_unacked_seq) {
		// Update the last unacked seq
		last_unacked_seq = ack;

		//measure rtt
		if (d3_ack_packet->allocated_rate != -1 && seq_measure_rtt <= ack
				&& !send_rate_reuqst) {
			seq_measure_rtt = -1;
			rtt = get_current_time() - last_moment_request_sent;
			send_rate_reuqst = true;

			current_rate = d3_ack_packet->allocated_rate;
			// Adjust cwnd
			increase_cwnd();
			send_pending_data();
		}

		// Update the retx timer
		if (retx_event != NULL) { // Try to move
			cancel_retx_event();
			if (last_unacked_seq < size) {
				// Move the timeout to last_unacked_seq
				double timeout = get_current_time() + retx_timeout;
				set_timeout(timeout);
			}
		}

	}

	//if (ack == size && !finished) {
	if (d3_ack_packet->last_packet && !finished) {
		finished = true;
		received.clear();
		finish_time = get_current_time();
		if (ack != size) {
			//if the flow has been canceled
			finish_time = get_current_time() + 2 * this->deadline;
		} else {
			finish_time = get_current_time();
		}
		flow_completion_time = finish_time - start_time;
		FlowFinishedEvent *ev = new FlowFinishedEvent(finish_time, this);
		add_to_event_queue(ev);
	}
}

void D3Flow::increase_cwnd() {
	uint32_t usefull_bytes = ((current_rate / 8) * (rtt-params.switching_delay));
	usefull_bytes -= (usefull_bytes / (mss + hdr_size)) * hdr_size;
	cwnd_mss = usefull_bytes;
	//cwnd_mss = std::min(cwnd_mss, max_cwnd);
	cwnd_mss = std::max(cwnd_mss, mss);
	std::cerr<<"WND "<<cwnd_mss<<" "<<rtt<<" "<<current_rate<<"\n";
}

void D3Flow::receive_data_pkt(Packet* p) {
	received_count++;
	total_queuing_time += p->total_queuing_delay;
	std::vector<uint32_t> sack_list;
	uint32_t number_of_bytes = p->size - hdr_size;
	uint32_t diff = p->seq_no - recv_till;
	received_bytes += number_of_bytes;
	if (diff >= 0 && diff <= mss) {
		recv_till = p->seq_no + number_of_bytes;
	}
	send_ack(p, recv_till, sack_list);
}

void D3Flow::send_ack(Packet* received_packet, uint32_t seq,
		std::vector<uint32_t> sack_list) {
	D3Packet* rp = (D3Packet*) received_packet;
	//std::cerr<<id<<" RECEIVED "<< rp->seq_no << " "<<seq<<std::endl;
	double final_rate = DBL_MAX / 2;
	if (rp->rate_request) {
		for (int i = 0; i < rp->new_allocation.size(); i++) {
			final_rate = std::min(final_rate, rp->new_allocation[i]);
		}
	} else {
		final_rate = -1;
	}

	bool finish_now = false;
	if (seq == rp->flow->size) {
		finish_now = true;
	}
	Packet *p = new D3PacketAck(this, seq, sack_list, hdr_size, dst, src,
			final_rate, finish_now); //Acks are dst->src
	add_to_event_queue(
			new PacketQueuingEvent(get_current_time(), p, dst->queue));
}

uint32_t D3Flow::get_priority(uint32_t seq) {
	return 1;
}

void D3Flow::handle_timeout() {
	if (finished)
		return;
	std::cerr<<id<<" TIMEOUT "<<last_unacked_seq<<std::endl;
	next_seq_no = last_unacked_seq;
	//Reset congestion window to 1
	cwnd_mss = 1 * mss;
	send_rate_reuqst = true;
	send_pending_data();
	set_timeout(get_current_time() + retx_timeout);
}
