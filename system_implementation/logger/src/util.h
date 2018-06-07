#ifndef _UTIL_WRAP_
#define _UTIL_WRAP_

#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CALL_NETWORK_SEND 1
#define CALL_DISK_WRITE 2

#define CALL_NETWORK_READ 10
#define CALL_DISK_READ 20

int read_socket_information(int fd, struct sockaddr_in* addr);
void send_all_messages(short call_type, int ip, int port, int data_sent);

void init_logger(void);
void end_logger(void);

#endif