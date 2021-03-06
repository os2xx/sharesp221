/* 
 * hello-1.c - The simplest kernel module. 
 */ 

#include <linux/kernel.h> /* Needed for pr_info() */ 
#include <linux/module.h> /* Needed by all modules */ 

int init_module(void) 
{ 
    pr_info("ZCZC M01 hello01 START\n"); 

    /* A non 0 return means init_module failed; module can't be loaded. */ 
    return 0; 
} 

void cleanup_module(void) 
{ 
    pr_info("ZCZC M01 hello01 STOP\n"); 
} 

MODULE_LICENSE("GPL");
MODULE_AUTHOR("dewa251202");
