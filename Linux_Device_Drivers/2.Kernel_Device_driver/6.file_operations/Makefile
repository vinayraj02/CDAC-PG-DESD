obj-m := file.o
	KER_D=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)
all:
	$(MAKE) -C $(KER_D) M=$(PWD) modules
clean:
	$(MAKE) -C $(KER_D) M=$(PWD) clean
