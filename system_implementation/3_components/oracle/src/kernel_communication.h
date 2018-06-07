#ifndef __KERNEL_COMMUNICATION__
#define __KERNEL_COMMUNICATION__

#define NETLINK_USER 31
#define MAX_PAYLOAD 1024 /* maximum payload size*/
#define CALL_ORACLE (0x100)
#define CALL_SYSCALL (0x80)

int socket_initialize();
void send_prediction_to_kernel(short call_type, unsigned int hash, int size);
void send_message_kernel(char * data, int length);

#endif