/*
 * hello05.c
 */
#define VERSION     "REV01"
#define ZCZCHEADER  "ZCZC M05"
#define DESCRIPTION "hello05"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"

#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 

static int _init_5(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    return 0; 
} 
 
static void _exit_5(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
} 
 
module_init(_init_5); 
module_exit(_exit_5); 

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

