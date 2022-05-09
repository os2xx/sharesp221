#define VERSION     "REV01"
// REV01: Mon 25 Apr 2022 22:30:00 WIB
// START: Mon 04 Apr 2022 17:00:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M05"
#define DESCRIPTION "hello05"
#define procfs_name "helloworld"
#define AUTHOR      "C. BinKadal"
#define LICENSE     "GPL"

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init hello05_start(void) {
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    return 0;
}

static void __exit hello05_end(void) {
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

module_exit(hello05_end);
module_init(hello05_start);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

