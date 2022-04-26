/* 
 * hello02a.c - Illustration of multi filed modules 
 */ 
#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "hello02"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"

 
#include <linux/kernel.h> /* We are doing kernel work */ 
#include <linux/module.h> 
#include <linux/init.h>  
 
static int h_init(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    return 0; 
} 

module_init(h_init);
 
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
