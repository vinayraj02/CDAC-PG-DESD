obj-m:=spin.o
	ker:=/lib/modules/$(shell uname -r)/build
	pwd:=$(shell pwd)
all:
	make -C $(ker) M=$(pwd) modules
	gcc -o read read.c
	gcc -o write write.c
clean:
	make -C $(ker) M=$(pwd) clean
	rm -rf write read