/* 
 * hello02a.c - Illustration of multi filed modules 
 */ 
 
#include <linux/kernel.h> /* We are doing kernel work */ 
#include <linux/module.h> 
#include <linux/init.h>  
 
static int h_init(void) 
{ 
    pr_info("ZCZC M02 hello02 START\n"); 
    return 0; 
} 

module_init(h_init);
 
MODULE_LICENSE("GPL");
