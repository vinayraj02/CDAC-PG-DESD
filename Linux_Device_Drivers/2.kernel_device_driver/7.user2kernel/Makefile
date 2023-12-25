obj-m:= ker.o
	KER_DIR:=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)
all:
	$(MAKE) -C $(KER_DIR) M=$(PWD) modules
	gcc -o user user.c
clean:
	$(MAKE) -C $(KER_DIR) M=$(PWD) clean
	rm -rf user
