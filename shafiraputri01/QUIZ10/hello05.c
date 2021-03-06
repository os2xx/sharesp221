/*
 * hello05.c
 */
#define VERSION     "REV03"
// REV03: Thu 19 May 2022 16:50:00 WIB
// REV02: Tue 17 May 2022 14:50:00 WIB
// REV01: Tue 10 May 2022 14:50:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M05"
#define DESCRIPTION "A template with module_init()/module_exit()"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"

#define pr_fmt(fmt) ZCZCHEADER " " KBUILD_MODNAME ": " fmt

#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 

static int __init hello05_init(void) 
{ 
    pr_info("%s - %s\n", DESCRIPTION, "START");
    return 0; 
} 
 
static void __exit hello05_exit(void) 
{ 
    pr_info("%s - %s\n", DESCRIPTION, "STOP");
} 
 
module_init(hello05_init); 
module_exit(hello05_exit); 

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

