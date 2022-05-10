#define ZCZCHEADER  "ZCZC M01"
#define DESCRIPTION "hello01"

#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void) {
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    return 0;
}

void cleanup_module(void) {
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

MODULE_LICENSE("GPL");
