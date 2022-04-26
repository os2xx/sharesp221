/* 
 * hello02b.c - Illustration of multi filed modules 
 */ 
#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "hello02"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"

#include <linux/kernel.h> /* We are doing kernel work */ 
#include <linux/module.h>
#include <linux/init.h>
 
void h_exit(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP"); 
}

module_exit(h_exit) 
 
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);