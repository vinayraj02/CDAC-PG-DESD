obj-m:=sem.o
	KERD:=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)
all:
	make -C $(KERD) M=$(PWD) modules
	gcc -o read read.c
	gcc -o wrt1 wrt1.c
	gcc -o wrt2 wrt2.c
clean:
	make -C $(KERD) M=$(PWD) clean
	rm -rf read wrt1 wrt2