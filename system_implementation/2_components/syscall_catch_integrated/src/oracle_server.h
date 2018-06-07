#ifndef _ORACLE_SERVER_
#define _ORACLE_SERVER_

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define PIPE_NAME "/tmp/oracle_pipe"
#define BUFF_SIZE 32003

#define XGBOOST_NUMBER_OF_FEATURES 44
#define XGBOOST_TEST_EXAMPLES 200
#define XGBOOST_SCALE_FACTOR 15000

//50ms in ns
#define FLOW_GAP 50000000

void initialize_oracle(void);
int new_call_received(unsigned int hash, int size);
int predict(void);

#endif