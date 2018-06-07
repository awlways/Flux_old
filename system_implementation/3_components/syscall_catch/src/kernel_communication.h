#ifndef __KERNEL_COMMUNICATION__
#define __KERNEL_COMMUNICATION__

#define NETLINK_USER 31
#define MAX_PAYLOAD 32 /* maximum payload size*/
#define MESSAGE_LENGTH (sizeof(unsigned int)+sizeof(int)+sizeof(short))

int socket_initialize();
void send_message_kernel(char * data, int length);
void send_all_messages(short call_type, int ip, int port, int data_sent);

void initialize_oracle_write(void);
void destroy_oracle_write(void);
void oracle_write(char* buffer, int size);

#endif