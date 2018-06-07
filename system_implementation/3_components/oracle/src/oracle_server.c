#include "oracle_server.h"
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "thpool.h"
#include "kernel_communication.h"
#include <c_api.h>
#include "predictor.h"

struct flow{
    unsigned long long time;
    unsigned char active;    
};

int oracle_fd;
char* oracle_pipe = PIPE_NAME;
struct flow flow_storage[BUFF_SIZE];
threadpool thpool;

BoosterHandle handle;
float xgboost_test_data[XGBOOST_TEST_EXAMPLES][XGBOOST_NUMBER_OF_FEATURES];

unsigned int hash_flow(unsigned int dst_ip, unsigned short dst_port, unsigned short src_port) {
    unsigned int x;
    if(dst_ip == 16777343){
        dst_ip = 0;
    }
    x = dst_ip + dst_port + src_port;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x % BUFF_SIZE;
}

void initialize_oracle_read(void){
    int i;
    oracle_fd = -1;
    while(oracle_fd == -1){
        oracle_fd = open(oracle_pipe, O_RDONLY);
    }

    //initialize flow structure
    for(i = 0; i < BUFF_SIZE; i++){
        flow_storage[i].time = 0;
        flow_storage[i].active = 0;
    }

    thpool =  thpool_init(NUMBER_OF_THREADS);

    //initialize xgboost model
}

void destroy_oracle_read(void){
    close(oracle_fd);
}

void oracle_read(){
    char data[MESSAGE_LENGTH];
    char gap = 0;
    int i;
    unsigned int* param;
    short call_type;
    unsigned int hash;
    int size;
    unsigned long long current_time;
    struct timespec tstart={0,0};

    i = read(oracle_fd, data, MESSAGE_LENGTH);
    if(i == 0){
        exit(0);
    }

    memcpy(&call_type, data, sizeof(short));
    memcpy(&hash, data + sizeof(short), sizeof(unsigned int));
    memcpy(&size, data + sizeof(short) + sizeof(unsigned int), sizeof(int));
    
    //get current time
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    current_time = ((unsigned long long)tstart.tv_sec)*1.0e9 + tstart.tv_nsec;

    gap = current_time - flow_storage[hash].time >FLOW_GAP?1:0;
    flow_storage[hash].time = current_time;
    if(gap && !flow_storage[hash].active){
        flow_storage[hash].active = 1;
        //printf("Received: %u \n", size);
        param = (unsigned int*) malloc(sizeof(unsigned int*));
        *param = hash;
        thpool_add_work(thpool, (void*)analyze_message, (void*)param);
    }
}

void analyze_message(void* param){
    int index;
    int prediction = 1000;
    unsigned int hash = *((int *) param);
    free(param);
    //sleep one millisecond
    //usleep(1000);
    index = rand() % XGBOOST_TEST_EXAMPLES;
    prediction = call_predict((float *) xgboost_test_data[index]);
    
    send_prediction_to_kernel(0, hash, prediction);
    
    flow_storage[hash].active = 0;
}

int call_predict(float * data){
    //struct timespec tstart={0,0}, tend={0,0};
    //unsigned int elapsed;
    DMatrixHandle h_test;
    bst_ulong out_len;
    const float *f;

    //clock_gettime(CLOCK_MONOTONIC, &tstart);

    //XGDMatrixCreateFromMat(data, 1, XGBOOST_NUMBER_OF_FEATURES, -1, &h_test);
    //XGBoosterPredict(handle, h_test, 0, 0, &out_len,&f);
    predict_margin((union Entry*)data);
    // free xgboost internal structures
    //XGDMatrixFree(handle);
    //XGDMatrixFree(h_test);

    //clock_gettime(CLOCK_MONOTONIC, &tend);

    //elapsed = ((et.tv_sec - st.tv_sec) * 1000000) + (et.tv_usec - st.tv_usec);
    //elapsed = ((unsigned long long)tend.tv_sec)*1.0e9 + tend.tv_nsec;
    //elapsed -= ((unsigned long long)tstart.tv_sec)*1.0e9 + tstart.tv_nsec;
    //printf("%u\n",elapsed);

    return f[0]*XGBOOST_SCALE_FACTOR;;
}

void initialize_xgboost(void){
    int res, i, j;
    srand(time(NULL));

    // XGBoosterCreate(0, 0, &handle);
    // res = XGBoosterLoadModel(handle, XGBOOST_MODEL_PATH);

    //create input data
    for (i=0;i<XGBOOST_TEST_EXAMPLES;i++){
        for (j=0;j<XGBOOST_NUMBER_OF_FEATURES;j++){
            xgboost_test_data[i][j] = (float)rand()/(float)(RAND_MAX);
            //printf("%d %d %d %d \n",i,j, XGBOOST_TEST_EXAMPLES,XGBOOST_NUMBER_OF_FEATURES);
        }
    }

    for (i=0; i<WARM_UP_ORACLE; i++){
        predict_margin((float *) xgboost_test_data[rand() % XGBOOST_TEST_EXAMPLES]);
    }
    printf("XGboost load: %d\n", res);
}