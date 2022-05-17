#include <linux/init.h> /* Needed for the macros */
#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */

#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "hello02"
#define AUTHOR      "Samuel"
#define LICENSE     "GPL"
#define VERSION     "REV00"

static void __exit hello02_exit(void)
{
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

module_exit(hello02_exit);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
