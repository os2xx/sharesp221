/* 
 * hello-1.c - The simplest kernel module. 
 */ 

#include <linux/kernel.h> /* Needed for pr_info() */ 
#include <linux/module.h> /* Needed by all modules */ 

void module_init(void) 
{ 
    pr_info("ZCZC M02 hello02 STOP\n"); 
} 

MODULE_LICENSE("GPL");
MODULE_AUTHOR("dewa251202");
