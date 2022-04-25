#define VERSION     "v1.0"
#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "hello02"
#define AUTHOR      "Naufal Sani"
#define LICENSE     "GPL"

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

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
