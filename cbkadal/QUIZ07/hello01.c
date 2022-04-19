#define VERSION     "REV03"
// REV03: Mon 18 Apr 2022 22:00:00 WIB
// REV02: Sun 03 Apr 2022 14:30:00 WIB
// START: Wed 30 Mar 2022 16:30:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M01"
#define DESCRIPTION "hello01"
#define AUTHOR      "C. BinKadal"
#define LICENSE     "GPL"

#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void) {
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    return 0;
}

void cleanup_module(void) {
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

