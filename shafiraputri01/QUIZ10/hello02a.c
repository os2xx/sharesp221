/* 
 * hello02a.c - Illustration of multi filed modules 
 */ 
#define VERSION     "REV02"
// REV02: Tue 17 May 2022 14:50:00 WIB
// REV01: Tue 10 May 2022 14:50:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M02"
#define DESCRIPTION "A module with init_module()/clean_module()"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"

#define pr_fmt(fmt) ZCZCHEADER KBUILD_MODNAME ": " fmt
 
#include <linux/kernel.h> /* We are doing kernel work */ 
#include <linux/module.h> 
#include <linux/init.h>  
 
static int h_init(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    return 0; 
} 

module_init(h_init);
 
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);