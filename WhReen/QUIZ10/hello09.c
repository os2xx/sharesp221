#define VERSION "REV01"
// REV02: Thu 17 May 2022 13:25:00 WIB
// START: Mon 04 Apr 2022 17:00:00 WIB

#define ZCZCHEADER  "ZCZC M09"
#define DESCRIPTION "hello09, simplefs"
#define AUTHOR      "WhReen, referencing cbkadal's"
#define LICENSE     "GPL"

#define pr_fmt(fmt) ZCZCHEADER KBUILD_MODNAME ": " fmt

#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */
#include <linux/init.h>

static int __init hello09_start(void)
{
    pr_info("%s - %s\n", DESCRIPTION, "START");
    /* A non 0 return means init_module failed; module can't be loaded. */
    return 0;
}

static void __exit hello09_end(void)
{
    pr_info("%s - %s\n", DESCRIPTION, "STOP");
}

module_init(hello09_start);
module_exit(hello09_end);

MODULE_LICENSE(LICENSE);
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_VERSION(VERSION);
