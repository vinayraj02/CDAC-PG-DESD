#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/types.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VK");

dev_t dev=MKDEV(400,0);

static int stat_i(void){
	printk("\n entered into the static kernel\n");
	register_chrdev_region(dev,1,"vkchardriver");
	printk("\n major:%d and minor:%d\n",MAJOR(dev),MINOR(dev));
	return 0;
}

static void stat_e(void){
	printk("\n exit from the static kernel\n");
	}

module_init(stat_i);
module_exit(stat_e);


/*to insert the device name into the kernel we should have a device file that can be created by the below command and this acts as the abstraction between user space and the driver which drives the service of the hardware to the user
	sudo mknod -m <permisions> /dev/<name of the file> c major minor
to remove this file from the devices list then use the below command
	sudo rm /dev/devices/<drivername>
 */
