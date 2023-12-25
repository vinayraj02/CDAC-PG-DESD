#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/device.h>

dev_t dev=0;
static struct cdev my_cdev;
static struct class *my_class;

static int my_open(struct inode *inode, struct file *file);
static int my_release(struct inode *inode, struct file *file);
static ssize_t my_read(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t my_write(struct file *filp, const char *buf, size_t len, loff_t *off);

static struct file_operations fo =
{
	.owner =THIS_MODULE,
	.open = my_open,
	.release = my_release,
	.read = my_read,
	.write = my_write,
};

static int my_open(struct inode *inode, struct file *file){
	printk("\n driver is open \n");
	return 0;
	}
static int my_release(struct inode *inode, struct file *file){
	printk("\n driver is closed \n");
	return 0;
	}
static ssize_t my_read(struct file *filp, char __user *buf, size_t len, loff_t *off){
	printk("\n driver is reading....!\n");
	return 0;
	}
static ssize_t my_write(struct file *filp, const char *buf, size_t len, loff_t *off){
	printk("\n driver is writing .....!\n");
	return len;
	}

static int char_i(void){
	alloc_chrdev_region(&dev,0,1,"vk_dev");
	printk("\n major :%d and minor :%d\n",MAJOR(dev),MINOR(dev));
	my_class=class_create(THIS_MODULE,"vk_device");
	device_create(my_class,NULL,dev,NULL,"vk_device");
	cdev_init(&my_cdev,&fo);
	cdev_add(&my_cdev,dev,1);
	printk("\n driver is inserted\n");
	return 0;
	}
static void char_e(void){
	device_destroy(my_class,dev);
	class_destroy(my_class);
	unregister_chrdev_region(dev,1);
	cdev_del(&my_cdev);
	printk("\n driver removed\n");
	}
	
module_init(char_i);
module_exit(char_e);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VK");


/*
steps to execute:
1.make
2.sudo insmod ./kernelobject.ko
3.cat /proc/devices                               // cat-> performs open,read and close
4.sudo dmesg | tail -5
5.mknod -m 777 /dev/<filename> c major minor    //no need of this if u create it automatically
6.ls -l /dev/<filename>
7.sudo su
8.echo 1 >/dev/<device_file_name                 //echo -> performs open,write and close
9.dmesg | tail -8
10.cat /dev/<device_file_name>
11.dmesg
12.exit 
13.rmnod /dev/device_name 						//skip this if you create automatically
14.rmmod <kernel_object_file>
*/
