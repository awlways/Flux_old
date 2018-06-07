#ifndef _TAGGER_INIT_
#define _TAGGER_INIT_

static int __init initialize(void) {
    struct netlink_kernel_cfg cfg = {
        .input = receive_message,
    };

    printk(KERN_INFO "Tagging module created!\n");

    //netfilter
    nfho.hook = packet_tagger;
    nfho.hooknum = NF_INET_POST_ROUTING;
    nfho.pf = PF_INET;
    nfho.priority = NF_IP_PRI_FIRST;
    nf_register_hook(&nfho);

    //communication - create socket
    //nl_sk = netlink_kernel_create(&init_net, NETLINK_USER, 0, hello_nl_recv_msg, NULL, THIS_MODULE);
    nl_sk = netlink_kernel_create(&init_net, NETLINK_USER, &cfg);
    if (!nl_sk) {
        printk(KERN_ALERT "Error creating socket.\n");
        return -10;
    }

    //initialize flow monitoring structure
    initialize_flow_info_storage();

    return 0;    
}

static void __exit teardown(void) {
    printk(KERN_INFO "Tagging module removed!\n");
    nf_unregister_hook(&nfho);

    //close socket
    netlink_kernel_release(nl_sk);

    destroy_flow_info_storage();
}

module_init(initialize);
module_exit(teardown);

#endif