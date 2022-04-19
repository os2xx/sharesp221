#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "hello02"

#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */

void cleanup_module(void)
{
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}
