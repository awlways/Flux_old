#include "util.h"

unsigned int hash_flow(unsigned int dst_ip, unsigned short dst_port, unsigned short src_port) {
    unsigned int x;
    
    if(dst_ip == 16777343){
        dst_ip = 0;
    }
    src_port = 0;

    x = dst_ip + dst_port + src_port;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x % MAXIMUM_NUMBER_OF_HASHES;
}

int read_socket_information(int fd, struct sockaddr_in* addr){
    int slen = sizeof(struct sockaddr_in);
    int res = getpeername(fd, (struct sockaddr *) addr, &slen);
    return res;
}
