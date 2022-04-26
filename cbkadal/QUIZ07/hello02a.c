#define VERSION     "REV02"
// REV02: Mon 18 Apr 2022 22:00:00 WIB
// REV01: Tue 05 Apr 2022 12:30:00 WIB
// START: Mon 04 Apr 2022 14:30:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "hello02"
#define AUTHOR      "C. BinKadal"
#define LICENSE     "GPL"

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init hello02_start(void) {
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    return 0;
}

module_init(hello02_start);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

