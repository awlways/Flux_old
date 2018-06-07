#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <errno.h>

#include "util.h"

#define ALLOW_LOCAL_WRITES 1

//void cinitialize(void) __attribute__((constructor));
void cinitialize(void) __attribute__((constructor));
void cdestroy(void) __attribute__((destructor));


/* Function pointers to hold the value of the glibc functions */
ssize_t (*real_sendfile)(int out_fd, int in_fd, off_t *offset, size_t count) = NULL;
ssize_t (*real_write)(int fd, const void *buf, size_t count) = NULL;
ssize_t (*real_sendmsg)(int socket, const struct msghdr *msg, int flags) = NULL;
ssize_t (*real_send)(int sockfd, const void *buf, size_t len, int flags) = NULL;
ssize_t (*real_sendto)(int sockfd, const void *buf, size_t len, int flags,
               const struct sockaddr *dest_addr, socklen_t addrlen) = NULL;

ssize_t (*real_read)(int fd, void *buf, size_t count);
ssize_t (*real_recv)(int sockfd, void *buf, size_t len, int flags);
ssize_t (*real_recvfrom)(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);
ssize_t (*real_recvmsg)(int sockfd, struct msghdr *msg, int flags);


void cinitialize(void) {
    real_sendfile = dlsym(RTLD_NEXT, "sendfile");
    real_write = dlsym(RTLD_NEXT, "write");
    real_sendmsg = dlsym(RTLD_NEXT, "sendmsg");
    real_send = dlsym(RTLD_NEXT, "send");
    real_sendto = dlsym(RTLD_NEXT, "sendto");

    real_read = dlsym(RTLD_NEXT, "read");
    real_recv = dlsym(RTLD_NEXT, "recv");
    real_recvfrom = dlsym(RTLD_NEXT, "recvfrom");
    real_recvmsg = dlsym(RTLD_NEXT, "recvmsg");

    init_logger();
}

void cdestroy(void){
    end_logger();
}


/* wrapping write function call */
ssize_t sendfile(int out_fd, int in_fd, off_t *offset, size_t count){
    struct sockaddr_in addr;
    int error;
    error = read_socket_information(out_fd, &addr);

    //if its network
    if(error!=-1){
        if(ALLOW_LOCAL_WRITES || addr.sin_addr.s_addr != 0){
            send_all_messages(CALL_NETWORK_SEND, addr.sin_addr.s_addr, addr.sin_port, count);
        }
    }
    
    return real_sendfile(out_fd, in_fd, offset, count);
}

ssize_t write(int fd, const void *buf, size_t count){
    struct sockaddr_in addr;
    int error;
    error = read_socket_information(fd, &addr);

    //if its network
    if(error!=-1){
        if(ALLOW_LOCAL_WRITES || addr.sin_addr.s_addr != 0){
            send_all_messages(CALL_NETWORK_SEND, addr.sin_addr.s_addr, addr.sin_port, count);
        }
    }else if(errno == ENOTSOCK){
        send_all_messages(CALL_DISK_WRITE, -1, -1, count);
    }
    
    return real_write(fd, buf, count);
}


ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags){
    struct sockaddr_in addr;
    int i;
    int error;
    error = read_socket_information(sockfd, &addr);

    if(error!=-1){
        if(ALLOW_LOCAL_WRITES || addr.sin_addr.s_addr != 0){
            int total_data = 0;
            //printf("SENDMSG %d %d \n", addr.sin_addr.s_addr, addr.sin_port);
            for(i=0; i<msg->msg_iovlen; i++){
                printf("%ld\n", msg->msg_iov[0].iov_len);
                total_data += msg->msg_iov[0].iov_len;
            }
            send_all_messages(CALL_NETWORK_SEND, addr.sin_addr.s_addr, addr.sin_port, total_data);
        }
    }

    return real_sendmsg(sockfd, msg, flags);
}


ssize_t send(int sockfd, const void *buf, size_t len, int flags){
    struct sockaddr_in addr;
    int error;
    error = read_socket_information(sockfd, &addr);

    if(error!=-1){
        if(ALLOW_LOCAL_WRITES || addr.sin_addr.s_addr != 0){
            //printf("SEND %d %d %ld\n", addr.sin_addr.s_addr, addr.sin_port, len);
            send_all_messages(CALL_NETWORK_SEND, addr.sin_addr.s_addr, addr.sin_port, len);
        }
    }
     
    return real_send(sockfd, buf, len, flags);
}


ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
               const struct sockaddr *dest_addr, socklen_t addrlen){
    struct sockaddr_in addr;
    int error;
    error = read_socket_information(sockfd, &addr);

    if(error!=-1){
        if(ALLOW_LOCAL_WRITES || addr.sin_addr.s_addr != 0){
            //printf("SENDTO %d %d %ld\n", addr.sin_addr.s_addr, addr.sin_port, len);
            send_all_messages(CALL_NETWORK_SEND, addr.sin_addr.s_addr, addr.sin_port, len);
        }
    }
    
    return real_sendto(sockfd, buf, len, flags, dest_addr, addrlen);
}

// READ ///////////////////////////////////////////////////////////////////////////////////////////

ssize_t read(int fd, void *buf, size_t count){
    struct sockaddr_in addr;
    int error;
    error = read_socket_information(fd, &addr);

    if(error!=-1){
        if(ALLOW_LOCAL_WRITES || addr.sin_addr.s_addr != 0){
            send_all_messages(CALL_NETWORK_READ, addr.sin_addr.s_addr, addr.sin_port, count);
        }
    }else if(errno == ENOTSOCK){
        send_all_messages(CALL_DISK_READ, -1, -1, count);
    }

    return real_read(fd, buf, count);
}

ssize_t recv(int sockfd, void *buf, size_t len, int flags){
    struct sockaddr_in addr;
    int error;
    error = read_socket_information(sockfd, &addr);

    if(error!=-1){
        if(ALLOW_LOCAL_WRITES || addr.sin_addr.s_addr != 0){
            send_all_messages(CALL_NETWORK_READ, addr.sin_addr.s_addr, addr.sin_port, len);
        }
    }
    return real_recv(sockfd, buf, len, flags);
}

ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen){
    struct sockaddr_in addr;
    int error;
    error = read_socket_information(sockfd, &addr);

    if(error!=-1){
        if(ALLOW_LOCAL_WRITES || addr.sin_addr.s_addr != 0){
            send_all_messages(CALL_NETWORK_READ, addr.sin_addr.s_addr, addr.sin_port, len);
        }
    }
    return real_recvfrom(sockfd, buf, len, flags, src_addr, addrlen);
}

ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags){
    struct sockaddr_in addr;
    int i;
    int error;
    error = read_socket_information(sockfd, &addr);

    if(error!=-1){
        if(ALLOW_LOCAL_WRITES || addr.sin_addr.s_addr != 0){
            int total_data = 0;
            //printf("SENDMSG %d %d \n", addr.sin_addr.s_addr, addr.sin_port);
            for(i=0; i<msg->msg_iovlen; i++){
                printf("%ld\n", msg->msg_iov[0].iov_len);
                total_data += msg->msg_iov[0].iov_len;
            }
            send_all_messages(CALL_NETWORK_READ, addr.sin_addr.s_addr, addr.sin_port, total_data);
        }
    }

    return real_recvmsg(sockfd, msg, flags);
}