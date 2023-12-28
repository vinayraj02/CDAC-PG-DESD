#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/wait.h>
#include<linux/kthread.h>


int wqf =0; //initializing the wait queue flag as 0 

dev_t dev;
static struct cdev mydev;
static struct class *myclass;
static struct task_struct *kthread;
wait_queue_head_t vw; //dynamic wait queue

static int      vk_open(struct inode *inode, struct file *file);
static int      vk_release(struct inode *inode, struct file *file);
static ssize_t  vk_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  vk_write(struct file *filp, const char *buf, size_t len, loff_t * off);

static struct file_operations fs=
{
    .owner = THIS_MODULE,
    .open = vk_open,
    .release = vk_release,
    .read = vk_read,
    .write = vk_write,
};


static int thf(void *arg){
    
    while(1){
        printk("waiting for the signal\n");
        wait_event_interruptible(vw, wqf != 0);
        if(wqf==1){
            printk("signal from the exit \n");
            return 0;
            
        }
        else{
            printk("signal came form the read/write\n");
             wqf = 0;
            
        }
    }
    do_exit(0);  
    return 0; 
}

static int      vk_open(struct inode *inode, struct file *file){
        printk("\n driver opened..!\n");
        return 0;
}
static int      vk_release(struct inode *inode, struct file *file){
        printk("\n driver closed.....!\n");
        return 0;
}
static ssize_t  vk_read(struct file *filp, char __user *buf, size_t len,loff_t * off){
        printk("\n driver reading.....!\n");
        wqf = 2;
        wake_up_interruptible(&vw);
        return len;
}
static ssize_t  vk_write(struct file *filp, const char *buf, size_t len, loff_t * off){
        printk("\n driver writing.....!\n");
        wqf = 2;
        wake_up_interruptible(&vw);
        return len;
}



static int ai(void){
    printk("in the kernel module\n");
    alloc_chrdev_region(&dev,0,3,"ker_dr");
    printk("major:%d and minor:%d\n",MAJOR(dev),MINOR(dev));
    myclass=class_create(THIS_MODULE,"vk_device");
    device_create(myclass,NULL,dev,NULL,"vk_device");
    cdev_init(&mydev,&fs);
    cdev_add(&mydev,dev,1);
    init_waitqueue_head (&vw);
    kthread = kthread_create(thf,NULL,"wait_th");
    wake_up_process(kthread);
    return 0;
}

static void ae(void){
    wqf = 1;
    wake_up_interruptible(&vw);
    cdev_del(&mydev);
    device_destroy(myclass,dev);
    class_destroy(myclass);
    unregister_chrdev_region(dev,1);
    printk("exit from the kernel\n");

}


module_init(ai);
module_exit(ae);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VK");
MODULE_DESCRIPTION("WAITQUEUE DRIVER");