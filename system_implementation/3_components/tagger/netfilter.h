#ifndef _TAGGER_NETFILTER_
#define _TAGGER_NETFILTER_
#define MAX_PRIORITY 63
#define PACKET_SIZE (2*1500)

unsigned int packet_tagger(unsigned int hooknum, struct sk_buff **skb, const struct net_device *in,
                       const struct net_device *out, int (*okfn)(struct sk_buff *)) {
    //unsigned short r;
    struct iphdr* iph;
    struct tcphdr* tcp_header;
    struct flow* fl;
    unsigned int seq;
    unsigned int hash;

    sock_buff = skb;

    if (!sock_buff) {
        return NF_ACCEPT;
    }

    iph = (struct iphdr *)skb_network_header(sock_buff);

    if (!iph) {
        return NF_ACCEPT;
    }

    if(iph->protocol==IPPROTO_TCP){
        tcp_header = tcp_hdr(skb);
        hash = hash_flow(iph->daddr, tcp_header->dest, 0);
        fl = find_existing_flow(hash);
        if(fl==NULL){
            iph->tos = 0;
        } else {
            //start new seq
            if(fl->start_seq == 0){
                fl->start_seq = ntohl(tcp_header->seq);
            }
            if(fl->size_estimated > ntohl(tcp_header->seq) - fl->start_seq){
                seq = fl->size_estimated - (ntohl(tcp_header->seq) - fl->start_seq);
                seq = seq / PACKET_SIZE;
                seq = seq > MAX_PRIORITY ? MAX_PRIORITY:seq;
                seq = seq <= 1 ? 1:seq;
            } else {
                seq = 0;
            }
            //printk(KERN_INFO "Priority: %d %u\n", seq, ntohl(tcp_header->seq));
        }
        iph->tos = seq << 2;
        
        /* Calculation of IP header checksum */
        iph->check = 0;
        iph->check = ip_fast_csum((u8 *)iph, iph->ihl);
    }
    return NF_ACCEPT;
}


#endif