#define VERSION     "REV03"
// REV03: Mon 18 Apr 2022 22:00:00 WIB
// REV02: Sun 03 Apr 2022 14:30:00 WIB
// START: Wed 30 Mar 2022 16:30:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M01"
#define DESCRIPTION "hello01"
#define AUTHOR      "C. BinKadal (Modified by WhReen)"
#define LICENSE     "GPL"

#include <linux/module.h> /* Needed for pr_info() */
#include <linux/kernel.h> /* Needed by all modules */

int init_module(void) {
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    /* A non 0 return means init_module failed; module can't be loaded. */
    return 0;
}

void cleanup_module(void) {
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
