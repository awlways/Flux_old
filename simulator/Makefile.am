AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = simulator simdebug

simulator_SOURCES = 				 		 	 \
					coresim/debug.cpp \
					coresim/event.cpp \
					coresim/flow.cpp \
					coresim/main.cpp \
					coresim/node.cpp \
					coresim/packet.cpp \
					coresim/queue.cpp \
					coresim/random_variable.cpp \
					coresim/topology.cpp \
					ext/capabilitybufferflow.cpp \
					ext/capabilityflow.cpp \
					ext/capabilityhost.cpp \
					ext/capabilitymeanflow.cpp \
					ext/d3flow.cpp \
					ext/d3topology.cpp \
					ext/dctcpFlow.cpp \
					ext/dctcpQueue.cpp \
					ext/factory.cpp \
					ext/fastpassbufferflow.cpp \
					ext/fastpassflow.cpp \
					ext/fastpasshost.cpp \
					ext/fastpassmeanflow.cpp \
					ext/fastpassTopology.cpp \
					ext/fifoflow.cpp \
					ext/fountainflow.cpp \
					ext/ideal.cpp \
					ext/magicflow.cpp \
					ext/magichost.cpp \
					ext/pfabricbuffer.cpp \
					ext/pfabricflow.cpp \
					ext/pfabricmeanflow.cpp \
					ext/pfabricoptimizedflow.cpp \
					ext/pfabricprobability.cpp \
					ext/pfabricqueue.cpp \
					ext/pfabricseq.cpp \
					ext/pfabricthreshold.cpp \
					ext/pfabricthresholdperfect.cpp \
					ext/schedulinghost.cpp \
					ext/tcpflow.cpp \
					run/params.cpp 		 	 	 \
					run/stats.cpp 			   	 \
					run/flow_generator.cpp       \
					trace_flow_generator.cpp       \
					trace_cdf_generator.cpp       \
					run/experiment.cpp 

simulator_CXXFLAGS = -g -O3 -gdwarf-2 -Wall -std=c++0x 

simdebug_SOURCES = $(simulator_SOURCES)

simdebug_CXXFLAGS  = -g -O0 -gdwarf-2 -Wall -std=c++0x 

#CFLAGS = -g -O3 -gdwarf-2 -Wall -std=c++0x 
#CXXFLAGS = -g -O3 -gdwarf-2 -Wall -std=c++0x 

