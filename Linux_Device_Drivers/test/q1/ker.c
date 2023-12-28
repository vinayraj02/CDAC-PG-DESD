#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>
#include<linux/device.h>
#include<linux/fs.h>
#include<linux/ioctl.h>
#include<linux/string.h>

#define MAGIC 'k'
#define GETSTATS _IOR(MAGIC, 1, struct stats *)


dev_t dev;
static struct cdev mydev;
static struct class *myclass;

static struct stats 
{
    int size;
    char buf[200];
    int r_w;
};

struct stats driver_stats = {0, "", 0};

static long vk_ioctl(struct file *filp, unsigned int cmd, unsigned long arg) {
    struct stats *data;

    switch (cmd) {
        case GETSTATS:
            data = (struct stats *)arg;
            if (copy_to_user(data, &driver_stats, sizeof(struct stats))) {
                printk("Error in ioctl\n");
                return -EFAULT;  // Error copying data to user space
            }

            break;
        default:
            printk("Unknown command\n");
            return -EINVAL;
    }

    return 0;
}

static ssize_t  vk_read(struct file *filp, char __user *buf, size_t len,loff_t * off){
    
    if(copy_to_user(buf,driver_stats.buf,len)){
        printk("error in copy\n");
        return -1;
    }
    
    driver_stats.r_w = 0;
    printk("reading done..!\n");
    return len;
}
static	ssize_t vk_write(struct file *file, const char __user *buf, size_t len, loff_t *off){
     if(copy_from_user(driver_stats.buf,buf,len)){
        printk("error in copy\n");
        return -1;
    }
     driver_stats.size = len;
     driver_stats.r_w = 1;
     printk("writing done..!\n");
    return len;
}
static    int vk_open (struct inode *inode, struct file *file){
    printk("driver opened\n");
    return 0;
}
static	int vk_release (struct inode *inode, struct file *file){
    printk("driver closed\n");
    return 0;
}

static struct file_operations fs=
{
    .owner = THIS_MODULE,
    .open = vk_open,
    .release = vk_release,
    .read = vk_read,
    .write = vk_write,
    .unlocked_ioctl = vk_ioctl,
};




static int keri(void){
    printk("in the kernel module\n");
    alloc_chrdev_region(&dev,0,3,"ker_dr");
    printk("major:%d and minor:%d\n",MAJOR(dev),MINOR(dev));
    myclass=class_create(THIS_MODULE,"vk_device");
    device_create(myclass,NULL,dev,NULL,"vk_device");
    cdev_init(&mydev,&fs);
    cdev_add(&mydev,dev,1);
    return 0;
}

static void kere(void){
    cdev_del(&mydev);
    device_destroy(myclass,dev);
    class_destroy(myclass);
    unregister_chrdev_region(dev,1);
    printk("exit from the kernel\n");

}


module_init(keri);
module_exit(kere);

MODULE_LICENSE("GPL");