#define VERSION     "REV02"
#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "hello02"
#define AUTHOR      "efsrdi"
#define LICENSE     "GPL"

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static void __exit hello_2_exit(void) {
        pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

module_exit(hello_2_exit);
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
