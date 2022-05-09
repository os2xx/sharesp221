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

static void __exit hello02_end(void) {
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

module_exit(hello02_end);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

