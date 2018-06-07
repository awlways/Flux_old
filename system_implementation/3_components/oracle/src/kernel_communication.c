#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include "kernel_communication.h"
#include "oracle_server.h"

struct sockaddr_nl src_addr, dest_addr;
struct nlmsghdr *nlh = NULL;
struct iovec iov;
int sock_fd = -1;
struct msghdr msg;

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

void send_prediction_to_kernel(short call_type, unsigned int hash, int size){
    char* msg;
    call_type = (call_type&~CALL_SYSCALL)|CALL_ORACLE;
    msg = (char*) malloc(MESSAGE_LENGTH);
    memcpy(msg, &call_type, sizeof(short));
    memcpy(msg + sizeof(short), &hash, sizeof(unsigned int));
    memcpy(msg + sizeof(short)+sizeof(unsigned int), &size, sizeof(int));
    
    //send to kernel
    send_message_kernel(msg, MESSAGE_LENGTH);

    free(msg);
}

void send_message_kernel(char * data, int length){
    memcpy(NLMSG_DATA(nlh), data, length);
    sendmsg(sock_fd, &msg, 0);
}