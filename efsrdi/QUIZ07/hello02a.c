#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "hello02"

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init hello_2_init(void) {
	pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
	return 0;
}

module_init(hello_2_init);
MODULE_LICENSE("GPL");
