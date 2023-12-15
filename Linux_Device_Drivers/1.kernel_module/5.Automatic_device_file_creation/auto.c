#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/device.h>

dev_t dev=0;
static struct class *auto_class; //sturct pointer for creating the name automatic


static int autoi(void){
    printk("\n inside the kernel...!\n");
    alloc_chrdev_region(&dev,0,1,"vk_ch");
    printk("\n major:%d and minor:%d\n",MAJOR(dev),MINOR(dev));
    
    /*class create with 2 aurguement one is for this module and another is device file name*/
    auto_class=class_create(THIS_MODULE,"vk_device");  
    device_create(auto_class,NULL,dev,NULL,"vk_device");
    return 0;
}

static void autoe(void){
    device_destroy(auto_class,dev);
    class_destroy(auto_class);
    unregister_chrdev_region(dev,1);
    printk("\n exit from the kernel....!\n");
}

module_init(autoi);
module_exit(autoe);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VK");
MODULE_DESCRIPTION("AUTOMATIC CREATING THE DEVICE NAME");