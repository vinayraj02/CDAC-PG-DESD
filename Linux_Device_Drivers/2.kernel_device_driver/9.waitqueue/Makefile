obj-m:= wq.o
	KER_DIR=/lib/modules/$(shell uname -r)/build
	PWD:=$(shell pwd)
default:
	$(MAKE) -C $(KER_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KER_DIR) M=$(PWD) clean
