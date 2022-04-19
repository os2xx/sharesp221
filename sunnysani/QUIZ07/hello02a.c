#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "hello02"

#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */

int init_module(void)
{
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");

    /* A non 0 return means init_module failed; module can't be loaded. */
    return 0;
}
