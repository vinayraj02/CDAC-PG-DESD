#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VL");

int add(int a,int b){
	return (a+b);
}

EXPORT_SYMBOL(add);

static int pi(void){
	printk("\n entered into the def mod\n");
	return 0;
}

static void pe(void){
	printk("\n exit from def mod\n");
}

module_init(pi);
module_exit(pe);
