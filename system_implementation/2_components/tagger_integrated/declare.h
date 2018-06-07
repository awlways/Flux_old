#ifndef _TAGGER_DECLARE_
#define _TAGGER_DECLARE_

#define NETLINK_USER 31
#define CALL_SYSCALL (0x80)
#define CALL_ORACLE (0x100)
#define CALL_REMOVE_MASK (~0x180)

#define NIPQUAD(addr) \
    ((unsigned char *)&addr)[0], \
    ((unsigned char *)&addr)[1], \
    ((unsigned char *)&addr)[2], \
    ((unsigned char *)&addr)[3]

#define BUFF_SIZE 32003

//50ms in ns
#define FLOW_GAP 50000000


struct flow {
    int prediction;
    unsigned int seq;
};

static struct flow* flow_info_storage[BUFF_SIZE];

static struct nf_hook_ops nfho;
struct sk_buff *sock_buff;
unsigned int sport, dport;

struct sock *nl_sk = NULL;

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
    return x % BUFF_SIZE;
}

void initialize_flow_info_storage(void){
    int i;
    for(i = 0; i < BUFF_SIZE; i++){
        flow_info_storage[i] = NULL;
    }
}

void destroy_flow_info_storage(void){
    int i;
    for(i = 0; i < BUFF_SIZE; i++){
        if(flow_info_storage[i] != NULL){
            kfree(flow_info_storage[i]);
        }
    }
}

void inster_new_flow(unsigned int hash, struct flow* new_flow){
    if(flow_info_storage[hash]){
        kfree(flow_info_storage[hash]);
    }
    flow_info_storage[hash] = new_flow;
}

struct flow* find_existing_flow(unsigned int hash){
    return flow_info_storage[hash];
}

struct flow* create_new_flow(unsigned int hash){
    struct flow* current_flow;
    current_flow = (struct flow*) kmalloc(sizeof(struct flow), GFP_KERNEL);
    current_flow->prediction = 0;
    current_flow->seq = 0;

    inster_new_flow(hash, current_flow);
    return current_flow;
}

#endif

