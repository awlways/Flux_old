SRCS_DIR:=src
BUILD_DIR:=bin
CURRENT_DIR := $(shell pwd)


CC=gcc
CFLAGS=-Wall -g -O3

CCSOURCES=$(wildcard $(SRCS_DIR)/*.c)


all:  build

build:
	$(CC) -fPIC -fno-stack-protector -g -shared $(CCSOURCES) -o $(BUILD_DIR)/logger.so  -ldl

clean:
	rm -rf bin/*
