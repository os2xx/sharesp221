/* 
 * hello-1.c - The simplest kernel module. 
 */ 

#include <linux/kernel.h> /* Needed for pr_info() */ 
#include <linux/module.h> /* Needed by all modules */ 

static int __init init_hello02(void) 
{ 
    pr_info("ZCZC M02 hello02 START\n"); 

    /* A non 0 return means init_module failed; module can't be loaded. */ 
    return 0; 
} 

module_init(init_hello02);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("dewa251202");
