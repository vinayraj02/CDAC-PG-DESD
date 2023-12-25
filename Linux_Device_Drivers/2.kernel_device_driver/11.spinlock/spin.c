#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/uaccess.h>
#include<linux/spinlock.h>

unsigned int ex_result; //shared resources
dev_t dev =0;
static struct cdev mydev;
static struct class *myclass;
spinlock_t sp;

static ssize_t s_read (struct file *, char __user *, size_t, loff_t *);
static ssize_t s_write (struct file *, const char __user *, size_t, loff_t *);
static int s_open (struct inode *, struct file *);
static int s_release (struct inode *, struct file *);

static struct file_operations fs=
{
    .owner = THIS_MODULE,
    .open = s_open,
    .release = s_release,
    .read = s_read,
    .write = s_write,
};

static ssize_t s_read (struct file *filp, char __user *buf, size_t len, loff_t *off){
    printk("driver reading\n");
    printk("data to be sent :%d\n",ex_result);
    if(copy_to_user((char *)buf,(char *)&ex_result,len)){
        printk("error in reading\n");
        return -1;
    }
    spin_unlock(&sp);  //unlocking
    return len;

}
static ssize_t s_write (struct file *filp, const char __user *buf, size_t len, loff_t *off){
    spin_lock(&sp);  //locking
    int kbuf[2];
    int num1,num2;
    printk("\ndriver writing\n");
    if(copy_from_user((char *)kbuf,(char *)buf,len)){
        printk("\n error in writing\n");
        return -1;
    }
    num1=kbuf[0];
    num2=kbuf[1];
    ex_result=kbuf[0]+kbuf[1];
    printk("\ndata is %d and %d\n",num1,num2);
    printk("\nresult is:%d\n",ex_result);
    return len;
}
static int s_open (struct inode *inode, struct file *file){
    printk("\n driver opened..!\n");
    return 0;
}
static int s_release (struct inode *inode, struct file *file){
    printk("\n driver closed...!\n");
    return 0;
}

static int semi(void){
    printk("\n inside them spinlock driver\n");
    alloc_chrdev_region(&dev,0,1,"sem_c");
    printk("\n major:%d and minor:%d\n",MAJOR(dev),MINOR(dev));
    myclass= class_create(THIS_MODULE,"vk_spin");
    device_create(myclass,NULL,dev,NULL,"vk_spin");
    cdev_init(&mydev,&fs);
    cdev_add(&mydev,dev,1);
    spin_lock_init(&sp);  //only one shared resource critical section which is result. 
    return 0;
}

static void seme(void){
    cdev_del(&mydev);
    device_destroy(myclass,dev);
    class_destroy(myclass);
    unregister_chrdev_region(dev,1);
    printk("\n exit from the spinlock driver\n");

}

module_init(semi);
module_exit(seme);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VK");
