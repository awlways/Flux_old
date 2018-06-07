#include "util.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define trashold 100

extern ssize_t (*real_write)(int fd, const void *buf, size_t count);

char* network_read = "_nr: %llu %d %d %d\n";
char* network_write = "_nw: %llu %d %d %d\n";
char* disk_read = "_dr: %llu %d\n";
char* disk_write = "_dw: %llu %d\n";


FILE* ff;
int flags = O_CREAT | O_APPEND;

void init_logger(void){
    ff = fopen("/tmp/ld_preload_logs", "a");
    //log_file = printf("HELLO %d\n",fileno(stdin));
    //real_write(log_file, "FILE CREATED\n", 13);
    fprintf(ff, "Library opened\n");
    //fsync(ff);
}

void end_logger(void){
    fprintf(ff, "Library destroyed\n");
    fclose(ff);
}

void send_all_messages(short call_type, int ip, int port, int data_sent){
    struct timespec ttime={0,0};
    unsigned long long current_time;
    char output_buffer[70];
    int output_size;
    
    if(data_sent<trashold){
        return;
    }
    clock_gettime(CLOCK_MONOTONIC, &ttime);
    current_time = ((unsigned long long)ttime.tv_sec)*1.0e9 + ttime.tv_nsec;
    switch(call_type){
        case CALL_NETWORK_SEND:
            output_size = sprintf(output_buffer, network_write, current_time, data_sent, ip, port);
            break;
        case CALL_DISK_WRITE:
            output_size = sprintf(output_buffer, disk_write, current_time, data_sent);
            break;
        case CALL_NETWORK_READ:
            output_size = sprintf(output_buffer, network_read, current_time, data_sent, ip, port);
            break;
        case CALL_DISK_READ:
            output_size = sprintf(output_buffer, disk_read, current_time, data_sent);
            break;
    }
    fprintf(ff, output_buffer);
    printf(output_buffer);
    //fprintf(fdopen(log_file,"a"), "HELLO\n");
    //real_write(log_file, output_buffer, output_size);
    fflush(ff);
}

int read_socket_information(int fd, struct sockaddr_in* addr){
    int slen = sizeof(struct sockaddr_in);
    int res = getpeername(fd, (struct sockaddr *) addr, &slen);
    return res;
}
