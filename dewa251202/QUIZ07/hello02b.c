/* 
 * hello-1.c - The simplest kernel module. 
 */ 

#include <linux/kernel.h> /* Needed for pr_info() */ 
#include <linux/module.h> /* Needed by all modules */ 

static void __exit exit_hello02(void) 
{ 
    pr_info("ZCZC M02 hello02 STOP\n"); 
} 

module_exit(exit_hello02);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("dewa251202");
