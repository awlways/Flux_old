#ifndef _TAGGER_COMMUNICATION_
#define _TAGGER_COMMUNICATION_
#include <linux/time.h>
#include <linux/ktime.h>

static void receive_message(struct sk_buff *skb) {
    struct nlmsghdr *nlh;
    int pid;
    char* data;
    struct timespec timestamp;
    

    //data received
    short call_type;
    unsigned int hash;
    int size;
    s64 time;

    nlh = (struct nlmsghdr *)skb->data;
    
    data = (char *)nlmsg_data(nlh);

    memcpy(&call_type, data, sizeof(short));
    memcpy(&hash, data + sizeof(short), sizeof(unsigned int));
    memcpy(&size, data + sizeof(short) + sizeof(unsigned int), sizeof(int));

    //get current time
    // ktime_get_real_ts(&timestamp);
    // 
    getnstimeofday(&timestamp);
    time = ktime_to_ns(timespec_to_ktime(timestamp));
    analyze_message(call_type, hash, size, time);

    pid = nlh->nlmsg_pid;
}

#endif

