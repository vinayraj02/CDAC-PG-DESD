obj-m:=b.o
	KER_D:=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)
all:
	make -C $(KER_D) M=$(PWD) modules
	
clean:
	make -C $(KER_D) M=$(PWD) clean
