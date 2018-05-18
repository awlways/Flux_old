#include "params.h"

#include <assert.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

DCExpParams params;

std::vector<double> parse_line(std::string line){
    std::vector<double> list;
    size_t pos = 0;
    std::string token;
    double value;
    while ((pos = line.find(",")) != std::string::npos) {
        token = line.substr(0, pos);
        value = atof(token.c_str());
        list.push_back(
        	value
        );
        line.erase(0, pos + 1);
    }
	value = atof(line.c_str());
	list.push_back(
		value
	);
    return list;
}

/* Read parameters from a config file */
void read_experiment_parameters(std::string conf_filename, uint32_t exp_type) {
    std::ifstream input(conf_filename);
    std::string line;
    std::string key;
    params.interarrival_cdf = "none";
    params.permutation_tm = 0;
    params.hdr_size = 40;
    params.mss = 1460;
    while (std::getline(input, line)) {
        std::istringstream lineStream(line);
        if (line.empty()) {
            continue;
        }


        lineStream >> key;
        assert(key[key.length()-1] == ':');
        key = key.substr(0, key.length()-1);
        if (key == "init_cwnd") {
            lineStream >> params.initial_cwnd;
        }
        else if (key == "max_cwnd") {
            lineStream >> params.max_cwnd;
        }
        else if (key == "retx_timeout") {
            lineStream >> params.retx_timeout_value;
        }
        else if (key == "queue_size") {
            lineStream >> params.queue_size;
        }
        else if (key == "propagation_delay") {
            lineStream >> params.propagation_delay;
        }
        else if (key == "bandwidth") {
            lineStream >> params.bandwidth;
        }
        else if (key == "queue_type") {
            lineStream >> params.queue_type;
        }
        else if (key == "flow_type") {
            lineStream >> params.flow_type;
        }
        else if (key == "num_flow") {
            lineStream >> params.num_flows_to_run;
        }
        else if (key == "flow_trace") {
            lineStream >> params.cdf_or_flow_trace;
        }
        else if (key == "cut_through") {
            lineStream >> params.cut_through;
        }
        else if (key == "mean_flow_size") {
            lineStream >> params.mean_flow_size;
        }
        else if (key == "load_balancing") {
            lineStream >> params.load_balancing;
        }
        else if (key == "preemptive_queue") {
            lineStream >> params.preemptive_queue;
        }
        else if (key == "big_switch") {
            lineStream >> params.big_switch;
        }
        else if (key == "host_type") {
            lineStream >> params.host_type;
        }
        else if (key == "imbalance") {
            lineStream >> params.traffic_imbalance;
        }
        else if (key == "load") {
            lineStream >> params.load;
        }
        else if (key == "traffic_imbalance") {
            lineStream >> params.traffic_imbalance;
        }
        else if (key == "reauth_limit") {
            lineStream >> params.reauth_limit;
        }
        else if (key == "magic_trans_slack") {
            lineStream >> params.magic_trans_slack;
        }
        else if (key == "magic_delay_scheduling") {
            lineStream >> params.magic_delay_scheduling;
        }
        else if (key == "capability_timeout") {
            lineStream >> params.capability_timeout;
        }
        else if (key == "use_flow_trace") {
            lineStream >> params.use_flow_trace;
        }
        else if (key == "smooth_cdf") {
            lineStream >> params.smooth_cdf;
        }
        else if (key == "burst_at_beginning") {
            lineStream >> params.burst_at_beginning;
        }
        else if (key == "capability_resend_timeout") {
            lineStream >> params.capability_resend_timeout;
        }
        else if (key == "capability_initial") {
            lineStream >> params.capability_initial;
        }
        else if (key == "capability_window") {
            lineStream >> params.capability_window;
        }
        else if (key == "capability_prio_thresh") {
            lineStream >> params.capability_prio_thresh;
        }
        else if (key == "capability_third_level") {
            lineStream >> params.capability_third_level;
        }
        else if (key == "capability_fourth_level") {
            lineStream >> params.capability_fourth_level;
        }
        else if (key == "capability_window_timeout") {
            lineStream >> params.capability_window_timeout;
        }
        else if (key == "ddc") {
            lineStream >> params.ddc;
        }
        else if (key == "ddc_cpu_ratio") {
            lineStream >> params.ddc_cpu_ratio;
        }
        else if (key == "ddc_mem_ratio") {
            lineStream >> params.ddc_mem_ratio;
        }
        else if (key == "ddc_disk_ratio") {
            lineStream >> params.ddc_disk_ratio;
        }
        else if (key == "ddc_normalize") {
            lineStream >> params.ddc_normalize;
        }
        else if (key == "ddc_type") {
            lineStream >> params.ddc_type;
        }
        else if (key == "deadline") {
            lineStream >> params.deadline;
        }
        else if (key == "schedule_by_deadline") {
            lineStream >> params.schedule_by_deadline;
        }
        else if (key == "avg_deadline") {
            lineStream >> params.avg_deadline;
        }
        else if (key == "magic_inflate") {
            lineStream >> params.magic_inflate;
        }
        else if (key == "interarrival_cdf") {
            lineStream >> params.interarrival_cdf;
        }
        else if (key == "num_host_types") {
            lineStream >> params.num_host_types;
        }
        else if (key == "permutation_tm") {
            lineStream >> params.permutation_tm;
        }
        else if (key == "dctcp_mark_thresh") {
            lineStream >> params.dctcp_mark_thresh;
        }
        else if (key == "hdr_size") {
            lineStream >> params.hdr_size;
            assert(params.hdr_size > 0);
        }
        else if (key == "bytes_mode") {
            lineStream >> params.bytes_mode;
        }
        else if (key == "mean_predicted_flow_size") {
            lineStream >> params.mean_predicted_flow_size;
        }
        else if (key == "topology_num_hosts") {
			lineStream >> params.num_hosts; //144
		} else if (key == "topology_num_agg_switches") {
			lineStream >> params.num_agg_switches; //9
		} else if (key == "topology_num_core_switches") {
			lineStream >> params.num_core_switches; //4

		} else if (key == "use_exact_traces") {
			lineStream >> params.use_exact_traces;
		} else if (key == "use_exact_distribution") {
			lineStream >> params.use_exact_distribution;
		} else if (key == "trace_location") {
			lineStream >> params.trace_location;
		} else if (key == "switching_delay") {
			lineStream >> params.switching_delay;


		} else if (key == "number_of_hosts"){
			lineStream >> params.number_of_hosts;
		} else if (key == "prediction_improvement"){
			lineStream >> params.prediction_improvement;

		} else if (key == "squeezing_factor"){
			lineStream >> params.squeezing_factor;
		} else if (key == "mss"){
			lineStream >> params.mss;
		} else if (key == "host_buffer_size"){
			lineStream >> params.host_buffer_size;
		} else if (key == "thresholds"){
			std::string line;
			lineStream >> line;
			params.thresholds = parse_line(line);
		}

        //else if (key == "dctcp_delayed_ack_freq") {
        //    lineStream >> params.dctcp_delayed_ack_freq;
        //}
        else {
            std::cout << "Unknown conf param: " << key << " in file: " << conf_filename << "\n";
            assert(false);
        }

        params.fastpass_epoch_time = 1500 * 8 * (FASTPASS_EPOCH_PKTS + 0.5) / params.bandwidth;

        params.param_str.append(line);
        params.param_str.append(", ");
    }
}
