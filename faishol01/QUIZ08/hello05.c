#include <linux/init.h> /* Needed for the macros */
#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */

#define ZCZCHEADER  "ZCZC M05"
#define DESCRIPTION "hello05"
#define AUTHOR      "faishol01"
#define LICENSE     "GPL"
#define VERSION     "REV00"

static int _hello05_init(void)
{
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    return 0;
}

static void _hello05_exit(void)
{
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

module_init(_hello05_init);
module_exit(_hello05_exit);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
