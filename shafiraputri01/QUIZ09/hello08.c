/*
 * hello08.c
 */
#define VERSION     "START"
#define ZCZCHEADER  "ZCZC M08"
#define DESCRIPTION "hello08"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"

#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/version.h>
#include <linux/fs.h> 
#include <linux/kobject.h> 
#include <linux/string.h> 
#include <linux/sysfs.h> 

static struct kobject *mymodule; 

static int hello08var = 0; 

static ssize_t hello08var_show(struct kobject *kobj, 
                               struct kobj_attribute *attr, char *buf) 
{ 
    pr_info("%s /sys/kernel/H08module/hello08var = %d\n", ZCZCHEADER, hello08var);
    return sprintf(buf, "%d\n", hello08var); 
} 
 
static ssize_t hello08var_store(struct kobject *kobj, 
                                struct kobj_attribute *attr, char *buf, 
                                size_t count) 
{ 
    sscanf(buf, "%du", &hello08var); 
    return count; 
} 

static struct kobj_attribute hello08var_attribute = 
    __ATTR(hello08var, 0660, hello08var_show, (void *)hello08var_store); 

static int __init hello08_init(void) 
{ 
    int error = 0;
        
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");

    mymodule = kobject_create_and_add("H08module", kernel_kobj); 
    if (!mymodule) 
        return -ENOMEM; 
 
    error = sysfs_create_file(mymodule, &hello08var_attribute.attr); 
    if (error) { 
        pr_info("failed to create the hello08var file " 
                "in /sys/kernel/H08module\n"); 
    }

    pr_info("%s /sys/kernel/H08module/hello08var [OK]\n", ZCZCHEADER);
    return error; 
} 
 
static void __exit hello08_exit(void) 
{ 
    kobject_put(mymodule); 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
} 
 
module_init(hello08_init); 
module_exit(hello08_exit); 

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

