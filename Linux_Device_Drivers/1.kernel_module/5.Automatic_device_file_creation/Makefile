obj-m:= auto.o
	KERDIR:=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)
all:
	$(MAKE) -C $(KERDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERDIR) M=$(PWD) clean
