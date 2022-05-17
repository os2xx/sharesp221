#define VERSION     "v1.0"
#define ZCZCHEADER  "ZCZC M09"
#define DESCRIPTION "simplefs"
#define AUTHOR      "Naufal Sani"
#define LICENSE     "GPL"

#include <linux/kernel.h>
#include <linux/module.h>

static int __init init_simplefs(void) 
{ 
    pr_info("%s %s%s\n", ZCZCHEADER, DESCRIPTION, ": A simple file system - START");
    pr_info("%s %s%s\n", ZCZCHEADER, DESCRIPTION, ": Module loaded");

    return 0; 
} 

static void __exit exit_simplefs(void) 
{ 
    pr_info("%s %s%s\n", ZCZCHEADER, DESCRIPTION, ": A simple file system - STOP");
} 

module_init(init_simplefs);
module_exit(exit_simplefs);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
