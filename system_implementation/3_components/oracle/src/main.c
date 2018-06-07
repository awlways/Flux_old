#include "kernel_communication.h"
#include "oracle_server.h"
#include <stdio.h>

int main() {
    socket_initialize();
    initialize_xgboost();
    initialize_oracle_read();
    printf("Initialization finished\n");
    
    while(1){
        oracle_read();
    }

    destroy_oracle_read();
}