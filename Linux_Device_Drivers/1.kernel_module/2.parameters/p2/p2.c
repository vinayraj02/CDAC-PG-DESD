#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("VK");

static int var,var2;  //these are for passnig command line aurguments

module_param(var,int,S_IRWXU);
module_param(var2,int,S_IRWXU);

static int p_init(void){
	printk("\n into the func\n");
	printk("%d\n",(var+var2));
	return 0;
}

static void p(void){
	printk("\n exit from the func\n");
}

module_init(p_init);
module_exit(p);

