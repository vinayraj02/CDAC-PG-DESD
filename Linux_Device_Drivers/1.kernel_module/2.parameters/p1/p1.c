#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR(" VK ");

static int var=20;

module_param(var,int,S_IRWXU);

static int p_init(void){
	printk("\nin the fun\n");
	printk("%d\n",var);
	return 0;
}

static void p_e(void){
	printk("\n exit from the func\n");
}

module_init(p_init);
module_exit(p_e);

