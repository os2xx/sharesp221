#include <linux/init.h> /* Needed for the macros */
#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */

#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "hello02"
#define AUTHOR      "azhar81"
#define LICENSE     "GPL"
#define VERSION     "1.1"

static int __init hello02_init(void)
{
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    return 0;
}

module_init(hello02_init);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
