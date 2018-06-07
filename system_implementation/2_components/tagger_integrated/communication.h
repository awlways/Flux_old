#ifndef _TAGGER_COMMUNICATION_
#define _TAGGER_COMMUNICATION_
#include <linux/time.h>
#include <linux/ktime.h>

static void receive_message(struct sk_buff *skb) {
    struct nlmsghdr *nlh;
    int pid;
    char* data;

    //data received
    short call_type;
    unsigned int hash;
    int prediction;

    nlh = (struct nlmsghdr *)skb->data;
    
    data = (char *)nlmsg_data(nlh);

    memcpy(&call_type, data, sizeof(short));
    memcpy(&hash, data + sizeof(short), sizeof(unsigned int));
    memcpy(&prediction, data + sizeof(short) + sizeof(unsigned int), sizeof(int));

    analyze_message(call_type, hash, prediction);

    pid = nlh->nlmsg_pid;
}

#endif

