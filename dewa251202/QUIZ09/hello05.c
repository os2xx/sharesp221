#include <linux/kernel.h> /* Needed for pr_info() */ 
#include <linux/module.h> /* Needed by all modules */ 

static int __init init_hello05(void) 
{ 
    pr_info("ZCZC M05 hello05 START\n"); 

    /* A non 0 return means init_module failed; module can't be loaded. */ 
    return 0; 
} 

static void __exit exit_hello05(void) 
{ 
    pr_info("ZCZC M05 hello05 STOP\n"); 
} 

module_init(init_hello05);
module_exit(exit_hello05);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("dewa251202");
