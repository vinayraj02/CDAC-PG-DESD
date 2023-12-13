#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include"v.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VK");

static int a=5,b=6;


static int p_init(void){
	printk("\n in the func \n");
	printk("%d",add(a,b));
	return 0;
}

static void p(void){
	printk("\n out of the func\n");
}

module_init(p_init);
module_exit(p);
