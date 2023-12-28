obj-m:=ker.o
	KER_D:=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)
all:
	make -C $(KER_D) M=$(PWD) modules
	gcc -o read read.c
	gcc -o write write.c
	gcc -o ioctl ioctl.c
clean:
	make -C $(KER_D) M=$(PWD) clean
	rm -rf read write ioctl