/*
 * hello05.c
 */
#define VERSION     "REV02"
// REV02: Tue 17 May 2022 14:50:00 WIB
// REV01: Tue 10 May 2022 14:50:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M05"
#define DESCRIPTION "A module with init_module()/clean_module()"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"

#define pr_fmt(fmt) ZCZCHEADER KBUILD_MODNAME ": " fmt

#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 

static int _init_5(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    return 0; 
} 
 
static void _exit_5(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
} 
 
module_init(_init_5); 
module_exit(_exit_5); 

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

