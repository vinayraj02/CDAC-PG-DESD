//the below three headers are basic to every module creation 
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
//the below header is for file operations
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/wait.h>
#include<linux/kthread.h>

DECLARE_WAIT_QUEUE_HEAD(wq);
int c=0;
int wqf=0;    // Initialize wait_queue_flag to 0
dev_t dev=0;
static struct cdev vkc;
static struct class *my_cl;
static struct task_struct *wait_thread;  
/*static: The static keyword in this context means that the variable wait_thread has internal linkage. 
It is visible only within the translation unit (source file) where it is declared, 
and it retains its value between function calls.

struct task_struct *: This declares a pointer variable of type "struct task_struct." 
The struct keyword is used to define a structure, and in this case, task_struct is likely a structure used to 
represent a task or thread in a multithreaded program. The pointer (*) indicates that wait_thread will 
store the memory address of a structure of type task_struct.*/

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


static int wait_f(void *arg) {

    while(1){
    printk("\n waiting for the signal..!\n");

    // Wait until wait_queue_flag is not equal to 0
    wait_event_interruptible(wq, wqf != 0);

    // Check if the event came from the exit function
    if (wqf == 1) {
        printk("\n event from the exit function\n");
        return 0;
    }

    // Event came from the read function
    printk("\nevent from the read function %d\n", ++c);

    // Reset wait_queue_flag
    wqf = 0;
    }
    // Exit the kernel thread after handling the event
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
        wqf=2;
        wake_up_interruptible(&wq);
        /*When this function is called, it triggers the waking up of all 
        processes or threads that are currently sleeping on the specified wait queue.*/
        return 0;
}
static ssize_t  vk_write(struct file *filp, const char *buf, size_t len, loff_t * off){
        printk("\n driver writing.....!\n");
        return len;
}



static int wi(void){
    printk("\n inside the waitqueue driver\n");
    alloc_chrdev_region(&dev,0,1,"vk_ch");
    printk("\n major :%d and minor :%d\n",MAJOR(dev),MINOR(dev));
    my_cl=class_create(THIS_MODULE,"vk_device");
    device_create(my_cl,NULL,dev,NULL,"vk_device");
    cdev_init(&vkc,&fs);
    cdev_add(&vkc,dev,1);
    wait_thread=kthread_create(wait_f,NULL,"waitthread");
     /*{wait_thread: This is the previously declared static variable of type struct task_struct * that will be 
        assigned the value returned by kthread_create.

        kthread_create: This is a function used in the Linux kernel to create kernel threads. It takes three parameters:

        wait_function: This is likely a function pointer to the function that the kernel thread will execute. 
        The thread will start executing the code in the wait_function.

        NULL: This parameter typically represents the argument passed to the wait_function. In this case, it's set to NULL, 
        indicating that the kernel thread doesn't take any specific argument.

        "WaitThread": This is a string that provides a name for the kernel thread. It can be helpful for debugging and identifying the thread.

        The kthread_create function returns a struct task_struct *, which represents the newly created kernel thread. 
        The assignment wait_thread = kthread_create(...) stores this pointer in the wait_thread variable for potential further use, 
        such as for managing or terminating the thread.}*/
        
        wake_up_process(wait_thread);
    return 0;
}

static void we(void){
    wqf=1;
    wake_up_interruptible(&wq);
    cdev_del(&vkc);
    device_destroy(my_cl,dev);
    class_destroy(my_cl);
    unregister_chrdev_region(dev,1);
    printk("\n exit from the waitqueue driver\n");
}

module_init(wi);
module_exit(we);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VK");
MODULE_DESCRIPTION("WAITQUEUE DRIVER");
