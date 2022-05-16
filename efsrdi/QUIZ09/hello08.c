#define VERSION     "REV02"
#define ZCZCHEADER  "ZCZC M08"
#define DESCRIPTION "hello08"
#define AUTHOR      "Jim Huang, modified by efsrdi"
#define LICENSE     "GPL"
#define VAR         "/sys/H08module/hello08var"

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kobject.h>
#include <linux/module.h> 
#include <linux/string.h> 
#include <linux/sysfs.h>

static struct kobject *mymodule; 

static int hello08var = 0; 

static ssize_t hello08var_show(struct kobject *kobj, 
                               struct kobj_attribute *attr, char *buf) 
{ 
    pr_info("%s %s = %d\n", ZCZCHEADER, VAR, hello08var);
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

static int __init hello_8_init(void) 
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
    
    pr_info("%s %s %s\n", ZCZCHEADER, VAR, "[OK]");
    return error; 
}

static void __exit hello_8_exit(void) 
{ 
    pr_info("%s %s %s\n\n", ZCZCHEADER, DESCRIPTION, "STOP"); 
    kobject_put(mymodule); 
}

module_init(hello_8_init); 
module_exit(hello_8_exit); 

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
