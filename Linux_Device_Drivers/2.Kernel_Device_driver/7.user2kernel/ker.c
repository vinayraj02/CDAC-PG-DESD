#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include<linux/uaccess.h>
#include<linux/slab.h>


dev_t dev=0;
static struct cdev vk_cdev;
static struct class *my_class;
uint8_t kernel_buf[1024]="im from kernel";

	static int      vk_open(struct inode *inode, struct file *file);
static int      vk_release(struct inode *inode, struct file *file);
static ssize_t  vk_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  vk_write(struct file *filp, const char *buf, size_t len, loff_t * off);

static struct file_operations f=
{
	.owner = THIS_MODULE,
	.open = vk_open,
	.release = vk_release,
	.read = vk_read,
	.write = vk_write,
};

static int      vk_open(struct inode *inode, struct file *file){
	printk("\n file opend in kernel..!\n");
	return 0;
}
static int      vk_release(struct inode *inode, struct file *file){
	printk("\n file closed in kernel......!\n");
	return 0;
}
static ssize_t  vk_read(struct file *filp, char __user *buf, size_t len,loff_t * off){
	
	if(copy_to_user(buf,kernel_buf,1024)){
		printk("\n error in readig");
		return -1;
	}
	printk("\n driver reading done");
	return 1024;    
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	
static ssize_t  vk_write(struct file *filp, const char *buf, size_t len, loff_t * off){
	if(copy_from_user(kernel_buf,buf,len)){
		printk("\n error in writing");
		return -1;
	}
	printk("\n %s\n",kernel_buf);
	printk("\n driver writing done");
	
	return len;
}

static int ker_i(void){
	printk("\n kernel space\n");
	alloc_chrdev_region(&dev,0,1,"vk_ch");
	printk("\n major:%d and minor:%d\n",MAJOR(dev),MINOR(dev));
	my_class=class_create(THIS_MODULE,"vk_device");
	device_create(my_class,NULL,dev,NULL,"vk_device");
	cdev_init(&vk_cdev,&f);
	cdev_add(&vk_cdev,dev,1);
	return 0;
}

static void ker_e(void){
	device_destroy(my_class,dev);
	class_destroy(my_class);
	cdev_del(&vk_cdev);
	unregister_chrdev_region(dev,1);
	printk("\n exit from kernel space\n");
}

module_init(ker_i);
module_exit(ker_e);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VK");
MODULE_DESCRIPTION("USER SPACE TO KERNEL SPACE");
