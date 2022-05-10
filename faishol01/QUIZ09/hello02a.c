/*
 * hello02a.c - separate module
 */
#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */

static int _init_2(void)
{
    pr_info("ZCZC M02 hello02 START\n");

    /* A non 0 return means init_module failed; module can't be loaded. */
    return 0;
}

module_init(_init_2);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("faishol01");
MODULE_DESCRIPTION("hello02");
MODULE_VERSION("REV01");