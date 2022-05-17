/*
 * hello09.c
 */
#define VERSION     "START"
// START: Tue 17 May 2022 14:50:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M09"
#define DESCRIPTION "A simple file system"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"

#define pr_fmt(fmt) ZCZCHEADER KBUILD_MODNAME ": " fmt

#include <linux/fs.h> 
#include <linux/init.h> 
#include <linux/kobject.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/string.h> 
#include <linux/sysfs.h> 

static struct kobject *mymodule; 

static int _init simplefs_init(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");

    mymodule = kobject_create_and_add("mymodule", kernel_kobj); 
    if (!mymodule) 
        return -ENOMEM; 
 
    pr_info("%s %s\n", ZCZCHEADER, "Module loaded");

    return 0; 
} 
 
static void _exit simplefs_exit(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
} 
 
module_init(simplefs_init); 
module_exit(simplefs_exit); 

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

