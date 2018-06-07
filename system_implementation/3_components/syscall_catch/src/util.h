#ifndef _UTIL_WRAP_
#define _UTIL_WRAP_

#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdlib.h>

//sys calls
#define CALL_NETWORK_SEND (10)
#define CALL_SYSCALL (0x80)
#define MAXIMUM_NUMBER_OF_HASHES (32003)

int read_socket_information(int fd, struct sockaddr_in* addr);
unsigned int hash_flow(unsigned int dst_ip, unsigned short dst_port, unsigned short src_port);

#endif