#include <linux/kernel.h> /* Needed for pr_info() */ 
#include <linux/module.h> /* Needed by all modules */ 

static int __init init_hello09(void) 
{ 
    pr_info("ZCZC M09 hello09 START\n"); 

    /* A non 0 return means init_module failed; module can't be loaded. */ 
    return 0; 
} 

static void __exit exit_hello09(void) 
{ 
    pr_info("ZCZC M09 hello09 STOP\n"); 
} 

module_init(init_hello09);
module_exit(exit_hello09);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GSGS & dewa251202");
MODULE_VERSION("REV02");
MODULE_DESCRIPTION("A module for simplefs");
