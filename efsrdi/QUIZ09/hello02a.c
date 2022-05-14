#define VERSION     "REV02"
#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "hello02"
#define AUTHOR      "efsrdi"
#define LICENSE     "GPL"

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init hello_2_init(void) {
	pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
	return 0;
}

module_init(hello_2_init);
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
