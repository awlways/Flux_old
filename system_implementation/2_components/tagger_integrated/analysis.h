#ifndef _TAGGER_ANALYSIS_
#define _TAGGER_ANALYSIS_

void analyze_message(short call_type, unsigned int hash, int prediction){
    struct flow* current_flow;
    
    //printk(KERN_INFO "Received: %u %llu\n", size, time);
    
    current_flow = find_existing_flow(hash);
    if(current_flow == NULL){
        current_flow = create_new_flow(hash);
    }
    current_flow->prediction = 0;
    current_flow->seq = 0;
}

#endif