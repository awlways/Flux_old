#ifndef _ORACLE_SERVER_
#define _ORACLE_SERVER_

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define PIPE_NAME "/tmp/oracle_pipe"
#define MESSAGE_LENGTH (sizeof(unsigned int) + sizeof(int)+sizeof(short))
#define BUFF_SIZE 32003
#define NUMBER_OF_THREADS 10
#define WARM_UP_ORACLE 10

#define XGBOOST_MODEL_PATH "/home/voja/Downloads/xgboost.model"
#define XGBOOST_NUMBER_OF_FEATURES 42
#define XGBOOST_TEST_EXAMPLES 200
#define XGBOOST_SCALE_FACTOR 15000

//50ms in ns
#define FLOW_GAP 50000000

void initialize_oracle_read(void);
void destroy_oracle_read(void);
void oracle_read();
void analyze_message(void* param);
void initialize_xgboost(void);
int call_predict(float * data);

#endif