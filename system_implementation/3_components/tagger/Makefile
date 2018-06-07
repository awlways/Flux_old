#Filename: Makefile
obj-m := tagger.o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all: compile rmgarbage

compile:
		$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
rmgarbage:
		rm -r *.mod.c *.mod.o *.symvers *.order .tmp_versions && find -type f -name ".*" -delete
clean:
		rm -r *.ko *.mod.c *.mod.o *.symvers *.order .tmp_versions && find -type f -name ".*" -delete