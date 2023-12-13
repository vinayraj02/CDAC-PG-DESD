#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR(" vk ");

static int  hello_init(void)
{
printk("\nHello world\n");
return 0;
}

module_init(hello_init);

static void hello_exit(void)
{
printk("\n good bye,world\n");
}


module_exit(hello_exit);
