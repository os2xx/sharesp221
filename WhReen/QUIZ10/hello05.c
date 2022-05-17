#define VERSION "REV01"
// REV02: Thu 17 May 2022 13:25:00 WIB
// START: Mon 04 Apr 2022 17:00:00 WIB

#define ZCZCHEADER  "ZCZC M05"
#define DESCRIPTION "hello05"
#define AUTHOR      "WhReen, with help from cbkadal's hello05.c"
#define LICENSE     "GPL"

#define pr_fmt(fmt) ZCZCHEADER KBUILD_MODNAME ": " fmt

#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */
#include <linux/init.h>

static int __init hello05_start(void)
{
    pr_info("%s - %s\n", DESCRIPTION, "START");
    /* A non 0 return means init_module failed; module can't be loaded. */
    return 0;
}

static void __exit hello05_end(void)
{
    pr_info("%s - %s\n", DESCRIPTION, "STOP");
}

module_init(hello05_start);
module_exit(hello05_end);

MODULE_LICENSE(LICENSE);
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_VERSION(VERSION);
