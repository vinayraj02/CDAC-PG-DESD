#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>


#define s 500

dev_t dev=0;
static struct class *myclass;
static struct cdev my_dev;

char kernelbuf[s]="msg from the kernel";
char userbuf[s];

static int myopen(struct inode *inode, struct file *file);
static int myrelease(struct inode *inode, struct file *file);
static ssize_t myread(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t mywrite(struct file *filp, const char __user *buf, size_t len, loff_t *off);

static struct file_operations fs=
{
    .owner = THIS_MODULE,
    .open = myopen,
    .release = myrelease,
    .read = myread,
    .write = mywrite,
};

static int myopen(struct inode *inode, struct file *file){
    printk("\n driver opened...!\n");
    return 0;
}
static int myrelease(struct inode *inode, struct file *file){
    printk("\n driver closed..!\n");
    return 0;
}
static ssize_t myread(struct file *filp, char __user *buf, size_t len, loff_t *off){
    if(copy_to_user(buf,kernelbuf,s)){
        printk("\nerror in reading\n");
        return -1;
    }
    printk("\n driver reading....\n");
    return s;
}
static ssize_t mywrite(struct file *filp, const char __user *buf, size_t len, loff_t *off){
    if(copy_from_user(userbuf,buf,len)){
        printk("\n error in writing\n");
        return -1;
    }
    printk("\n driver writing....\n");
    return len;
}



static int keri(void){
    printk("\n entered into the module\n");
    alloc_chrdev_region(&dev,0,1,"mych");
    printk("\n major:%d and minor:%d\n",MAJOR(dev),MINOR(dev));
    myclass=class_create(THIS_MODULE,"file_ch");
    device_create(myclass,NULL,dev,NULL,"file_ch");
    cdev_init(&my_dev,&fs);
    cdev_add(&my_dev,dev,1);
    return 0;
}

static void kere(void){
    cdev_del(&my_dev);
    device_destroy(myclass,dev);
    class_destroy(myclass);
    unregister_chrdev_region(dev,1);
    printk("\n exit from the module\n");
}

module_init(keri);
module_exit(kere);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VK");