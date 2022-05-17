#define VERSION     "v1.1"
#define ZCZCHEADER  "ZCZC M01"
#define DESCRIPTION "hello01"
#define AUTHOR      "Naufal Sani"
#define LICENSE     "GPL"

#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void) {
    pr_info("%s %s%s\n", ZCZCHEADER, DESCRIPTION, ": A module with init_module()/clean_module() - START");
    return 0;
}

void cleanup_module(void) {
    pr_info("%s %s%s\n", ZCZCHEADER, DESCRIPTION, ": A module with init_module()/clean_module() - STOP");
}

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
