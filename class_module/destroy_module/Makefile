#ifneq ($(KERNELRELEASE),)
#obj-m:=hello.o
#else
#KDIR:=/lib/module/$(shell uname -r)/build
#PWD:=$(shell PWD)
#all:
#	make -C $(KDIR) = $(PWD) modules
#clean:
#	rm -rf *.ko *.o *.cmd *.cmd.o *.symvers
#endif

ifneq ($(KERNELRELEASE),)
obj-m:=destroy.o
else
KDIR := /lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)
all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm *.ko *.o *.symvers *.cmd *.cmd.o
endif

