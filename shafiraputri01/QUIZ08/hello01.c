/* 
 * hello-1.c - The simplest kernel module. 
 */ 
#define ZCZCHEADER  "ZCZC M01"
#define DESCRIPTION "hello01"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"

#include <linux/kernel.h> /* Needed for pr_info() */ 
#include <linux/module.h> /* Needed by all modules */ 
 
int init_module(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
 
    /* A non 0 return means init_module failed; module can't be loaded. */ 
    return 0; 
} 
 
void cleanup_module(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
} 
 
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);

