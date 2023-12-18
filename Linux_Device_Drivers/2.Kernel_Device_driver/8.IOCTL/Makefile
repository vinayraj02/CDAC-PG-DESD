obj-m:=ioctl.o
	KERDIR=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)
all:
	$(MAKE) -C $(KERDIR) M=$(PWD) modules
	gcc -o user user.c
clean:
	$(MAKE) -C $(KERDIR) M=$(PWD) clean
	rm -rf user
