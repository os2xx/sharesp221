#define VERSION     "REV03"
// REV03: Sun 15 May 2022 12:00:00 WIB
// REV02: Thu 05 May 2022 12:00:00 WIB
// REV01: Mon 25 Apr 2022 22:30:00 WIB
// START: Mon 04 Apr 2022 17:00:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.

#define ZCZCHEADER  "ZCZC M05 "
#define DESCRIPTION "A template with module_init()/module_exit()"
#define AUTHOR      "Based on Google Here and There by C. BinKadal"
#define LICENSE     "GPL"

#define pr_fmt(fmt) ZCZCHEADER KBUILD_MODNAME ": " fmt

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init hello05_start(void) {
    pr_info("%s - %s\n", DESCRIPTION, "START");
    return 0;
}

static void __exit hello05_end(void) {
    pr_info("%s - %s\n", DESCRIPTION, "STOP");
}

module_init(hello05_start);
module_exit(hello05_end);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

