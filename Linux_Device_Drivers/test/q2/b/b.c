#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include <linux/jiffies.h>
#include <linux/timer.h>

static int tout = 2000;
static struct timer_list time;

dev_t dev;

void tfunc(struct timer_list *data) {
    printk("In timer callback\n");

    mod_timer(data, jiffies + msecs_to_jiffies(tout));
}

static int ti(void) {
   
    printk("in the kernel module\n");
    alloc_chrdev_region(&dev,0,1,"ker_dr");
    printk("major:%d and minor:%d\n",MAJOR(dev),MINOR(dev));
    timer_setup(&time, tfunc, 0);  // init of timer
    mod_timer(&time, jiffies + msecs_to_jiffies(tout));  // start the timer for every 2 seconds

    return 0;
}

static void te(void) {
    del_timer(&time);
    unregister_chrdev_region(dev,1);
    printk("exit from kernel driver\n");
}

module_init(ti);
module_exit(te);

MODULE_LICENSE("GPL");
