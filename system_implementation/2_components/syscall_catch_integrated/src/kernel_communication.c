#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include "kernel_communication.h"
#include "util.h"
#include "oracle_server.h"
#include <time.h>

//oracle communication
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define PIPE_NAME "/tmp/oracle_pipe"

int oracle_fd;
char * oracle_pipe = PIPE_NAME;

struct sockaddr_nl src_addr, dest_addr;
struct nlmsghdr *nlh = NULL;
struct iovec iov;
int sock_fd = -1;
struct msghdr msg;

extern ssize_t (*real_sendmsg)(int socket, const struct msghdr *msg, int flags);
extern ssize_t (*real_write)(int fd, const void *buf, size_t count);

int socket_initialize(){
    sock_fd = socket(PF_NETLINK, SOCK_RAW, NETLINK_USER);
    if (sock_fd < 0)
        return -1;

    memset(&src_addr, 0, sizeof(src_addr));
    src_addr.nl_family = AF_NETLINK;
    src_addr.nl_pid = getpid(); /* self pid */

    bind(sock_fd, (struct sockaddr *)&src_addr, sizeof(src_addr));

    memset(&dest_addr, 0, sizeof(dest_addr));
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.nl_family = AF_NETLINK;
    dest_addr.nl_pid = 0; /* For Linux Kernel */
    dest_addr.nl_groups = 0; /* unicast */

    nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
    memset(nlh, 0, NLMSG_SPACE(MAX_PAYLOAD));
    nlh->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
    nlh->nlmsg_pid = getpid();
    nlh->nlmsg_flags = 0;

    iov.iov_base = (void *)nlh;
    iov.iov_len = nlh->nlmsg_len;
    msg.msg_name = (void *)&dest_addr;
    msg.msg_namelen = sizeof(dest_addr);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    return 0;
}


void send_message_kernel(char * data, int length){
    memcpy(NLMSG_DATA(nlh), data, length);
    real_sendmsg(sock_fd, &msg, 0);
}


void send_all_messages(short call_type, int ip, int port, int data_sent){
    char* msg;
    unsigned int hash;
    int prediction;

    struct timespec tstart={0,0}, tend={0,0};
    unsigned int elapsed;

    clock_gettime(CLOCK_MONOTONIC, &tstart);

    hash = hash_flow(ip, port, 0);
    prediction = new_call_received(hash, data_sent);
    call_type = call_type + CALL_SYSCALL;
    msg = (char*) malloc(MESSAGE_LENGTH);
    memcpy(msg, &call_type, sizeof(short));
    memcpy(msg + sizeof(short), &hash, sizeof(unsigned int));
    memcpy(msg + sizeof(short)+sizeof(unsigned int), &prediction, sizeof(int));
    
    
    //send to kernel
    send_message_kernel(msg, MESSAGE_LENGTH);

    free(msg);

    clock_gettime(CLOCK_MONOTONIC, &tend);
    elapsed = ((unsigned long long)tend.tv_sec)*1.0e9 + tend.tv_nsec;
    elapsed -= ((unsigned long long)tstart.tv_sec)*1.0e9 + tstart.tv_nsec;
    printf("x: %u\n",elapsed);
}
