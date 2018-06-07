#include "oracle_server.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "predictor.h"

struct flow{
    unsigned long long time;
    unsigned exact_size;
    unsigned prediction;
};

struct flow flow_storage[BUFF_SIZE];
float xgboost_test_data[XGBOOST_TEST_EXAMPLES][XGBOOST_NUMBER_OF_FEATURES];

void initialize_oracle(void){
    srand(time(NULL));    
    //init input
    for (int i=0;i<XGBOOST_TEST_EXAMPLES;i++){
        for (int j=0;j<XGBOOST_NUMBER_OF_FEATURES;j++){
            xgboost_test_data[i][j] = (float)rand()/(float)(RAND_MAX);
        }
    }

    for (int i=0;i<BUFF_SIZE;i++){
        flow_storage[i].time = 0;
        flow_storage[i].exact_size = 0;
        flow_storage[i].prediction = 0;
    }
}

int new_call_received(unsigned int hash, int size){
    unsigned long long current_time;
    struct timespec tstart={0,0};
    struct flow* current_flow;
    int prediction;
    
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    current_time = ((unsigned long long)tstart.tv_sec)*1.0e9 + tstart.tv_nsec;
    
    current_flow = &flow_storage[hash];
    if(current_time-current_flow->time >= FLOW_GAP){
        prediction = predict();
        current_flow->prediction = prediction<size?size:prediction;
        current_flow->exact_size = size;
    }else{
        prediction = predict();
        current_flow->exact_size += size;
        if(current_flow->exact_size > current_flow->prediction){
            current_flow->prediction = current_flow->exact_size;
        }
    }
    current_flow->time = current_time;
    return current_flow->prediction;
}

int predict(void){
    int index, prediction;

    //index = rand() % XGBOOST_TEST_EXAMPLES;
    index = 5;
    prediction = predict_margin( (union Entry*) xgboost_test_data[index])*XGBOOST_SCALE_FACTOR;

    return prediction;
}