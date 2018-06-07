SRCS_DIR:=src
BUILD_DIR:=bin
CURRENT_DIR := $(shell pwd)


CC=gcc
CFLAGS=-Wall -g -pthread
XGBOOST_PATH=-L/home/voja/work/code/xgboost/lib
XGBOOST_LIB=-lxgboost


CCSOURCES=$(wildcard $(SRCS_DIR)/*.c)
CINCLUDE=-I/home/voja/work/code/xgboost/include/xgboost -I/home/voja/work/code/xgboost/rabit/include/

all:  compile

compile:
	$(CC) $(CFLAGS) $(XGBOOST_PATH) $(CINCLUDE) $(CCSOURCES) -o $(BUILD_DIR)/oracle $(XGBOOST_LIB)

clean:
	rm -rf bin/*
