#ifndef _TAGGER_ANALYSIS_
#define _TAGGER_ANALYSIS_

void analyze_message(short call_type, unsigned int hash, int size, s64 time){
    struct flow* current_flow;

    //printk(KERN_INFO "Received: %u %llu\n", size, time);
    
    current_flow = find_existing_flow(hash);
    if(current_flow != NULL){
        if(call_type & CALL_SYSCALL){
            if(time - current_flow->last_call > FLOW_GAP){
                printk(KERN_INFO "CALL:%llu\n", time);
                current_flow->size_call = size;
                current_flow->size_estimated = size;
                current_flow->start_seq == 0;
            } else {
                current_flow->size_call += size;
                if(current_flow->size_call>current_flow->size_estimated){
                    current_flow->size_estimated = current_flow->size_call;
                }
            }
            current_flow->last_call = time;
        }else{
            printk(KERN_INFO "ORACLE:%llu\n", time);
            current_flow->last_estimated = time;
            current_flow->size_estimated = size;
        }
    } else {
        current_flow = create_new_flow(hash);
        current_flow->size_estimated = size;
        if(call_type & CALL_SYSCALL){
            printk(KERN_INFO "CALL:%llu\n", time);
            current_flow->last_call = time;
            current_flow->last_estimated = 0;
        } else{
            printk(KERN_INFO "ORACLE:%llu\n", time);
            current_flow->last_call = 0;
            current_flow->last_estimated = time;
        }
    }
}

#endif