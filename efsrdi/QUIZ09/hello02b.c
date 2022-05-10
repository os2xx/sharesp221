#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "hello02"

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static void __exit hello_2_exit(void) {
        pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

module_exit(hello_2_exit);
MODULE_LICENSE("GPL");
