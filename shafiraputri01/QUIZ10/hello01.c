/* 
 * hello-1.c - The simplest kernel module. 
 */
#define VERSION     "REV02"
// REV02: Tue 17 May 2022 14:50:00 WIB
// REV01: Tue 10 May 2022 14:50:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M01"
#define DESCRIPTION "A module with init_module()/clean_module()"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"

#define pr_fmt(fmt) ZCZCHEADER " " KBUILD_MODNAME ": " fmt

#include <linux/kernel.h> /* Needed for pr_info() */ 
#include <linux/module.h> /* Needed by all modules */ 
 
int init_module(void) 
{ 
    pr_info("%s - %s\n", DESCRIPTION, "START");
 
    /* A non 0 return means init_module failed; module can't be loaded. */ 
    return 0; 
} 
 
void cleanup_module(void) 
{ 
    pr_info("%s - %s\n", DESCRIPTION, "STOP");
} 
 
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

