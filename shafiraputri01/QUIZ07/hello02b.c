/* 
 * hello02b.c - Illustration of multi filed modules 
 */ 
 
#include <linux/kernel.h> /* We are doing kernel work */ 
#include <linux/module.h>
#include <linux/init.h>
 
void h_exit(void) 
{ 
    pr_info("ZCZC M02 hello02 STOP\n"); 
}

module_exit(h_exit) 
 
MODULE_LICENSE("GPL");
