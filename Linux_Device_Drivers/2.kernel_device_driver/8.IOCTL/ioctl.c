#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/device.h>
#include<linux/ioctl.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>
#include"ioctl.h"


dev_t dev=0;
static struct class *my_class;
static struct cdev vk_cdev;  //structure for charecter device registration

static int      vk_open(struct inode *inode, struct file *file);
static int      vk_release(struct inode *inode, struct file *file);
static ssize_t  vk_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  vk_write(struct file *filp, const char *buf, size_t len, loff_t * off);
static long     vk_ioctl(struct file *filp, unsigned int cmd, unsigned long arg);

static struct file_operations f={
    .owner = THIS_MODULE,
    .open = vk_open,
    .release = vk_release,
    .read = vk_read,
    .write = vk_write,
    .unlocked_ioctl	= vk_ioctl, //this specifies to implement the functionality
};

static int      vk_open(struct inode *inode, struct file *file){
    printk("\n driver opened..!\n");
    return 0;
}

static int      vk_release(struct inode *inode, struct file *file){
    printk("\n driver closed....!\n");
    return 0;
}

static ssize_t  vk_read(struct file *filp, char __user *buf, size_t len,loff_t * off){
    printk("\n driver reading done...!\n");
    return 0;
}

static ssize_t  vk_write(struct file *filp, const char *buf, size_t len, loff_t * off){
    printk("\n driver writing done....!\n");
    return len;
}

static long     vk_ioctl(struct file *filp, unsigned int cmd, unsigned long arg){
    printk("\n IOCTL invoked..!\n");
    switch(cmd)
    {
        case CMD_1:
            printk("\n this is CMD_1 command\n");
            break;
        case CMD_2:
            printk("\n this is CMD_2 command ... argument is %ld\n",arg);
            break;
        default:
            printk("\n invalid command\n");
            break;
    }
    return 0;
}

static int ioctl_i(void){
    printk("\n inside the ioctl kernel\n");
    alloc_chrdev_region(&dev,0,1,"vk_ch");
    printk("\n major:%d and minor:%d\n",MAJOR(dev),MINOR(dev));
    my_class=class_create(THIS_MODULE,"vk_device");
    device_create(my_class,NULL,dev,NULL,"vk_device");
    cdev_init(&vk_cdev,&f);
    cdev_add(&vk_cdev,dev,1);
    return 0;
}

static void ioctl_e(void){
    cdev_del(&vk_cdev);
    device_destroy(my_class,dev);
    class_destroy(my_class);
    unregister_chrdev_region(dev,1);
    printk("\n exit from the ioctl kernel...!\n");

}

module_init(ioctl_i);
module_exit(ioctl_e);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VK");
MODULE_DESCRIPTION("DEVICE CONFIGURATION PROGRAM");




