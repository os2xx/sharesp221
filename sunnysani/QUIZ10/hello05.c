#define VERSION     "v1.0"
#define ZCZCHEADER  "ZCZC M05"
#define DESCRIPTION "hello05"
#define AUTHOR      "Naufal Sani"
#define LICENSE     "GPL"

#include <linux/kernel.h>
#include <linux/module.h>

static int __init init_hello05(void) 
{ 
    pr_info("%s %s%s\n", ZCZCHEADER, DESCRIPTION, ": A template with module_init()/module_exit() - START");

    return 0; 
} 

static void __exit exit_hello05(void) 
{ 
    pr_info("%s %s%s\n", ZCZCHEADER, DESCRIPTION, ": A template with module_init()/module_exit() - STOP");
} 

module_init(init_hello05);
module_exit(exit_hello05);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
