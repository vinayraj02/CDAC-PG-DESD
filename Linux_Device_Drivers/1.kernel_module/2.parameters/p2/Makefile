obj-m := p2.o
	KERNELDIR=/lib/modules/$(shell uname -r)/build
	pwd:=(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
