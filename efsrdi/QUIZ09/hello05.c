#define VERSION     "REV02"
#define ZCZCHEADER  "ZCZC M05"
#define DESCRIPTION "hello05"
#define AUTHOR      "efsrdi"
#define LICENSE     "GPL"

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init hello_5_init(void) {
	pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
	return 0;
}

static void __exit hello_5_exit(void) {
        pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

module_init(hello_5_init);
module_exit(hello_5_exit);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
