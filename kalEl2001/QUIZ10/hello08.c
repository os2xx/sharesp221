#define ZCZCHEADER "ZCZC M08"
#define DESCRIPTION "hello08"
#define AUTHOR "Jim Huang, modified by Samuel"
#define LICENSE "GPL"
#define VERSION "REV00"

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kobject.h>
#include <linux/module.h>
#include <linux/string.h>
#include <linux/sysfs.h>

static struct kobject *H08module;

/* the variable you want to be able to change */
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

static int __init H08module_init(void)
{
    int error = 0;

    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START"); 

    // pr_info("H08module: initialised\n");

    H08module = kobject_create_and_add("H08module", kernel_kobj);
    if (!H08module)
        return -ENOMEM;

    error = sysfs_create_file(H08module, &hello08var_attribute.attr);
    if (error) {
        pr_info("%s failed to create the hello08var file "
                "in /sys/kernel/H08module\n", ZCZCHEADER);
    }

    pr_info("%s /sys/kernel/H08module/hello08var [OK]\n", ZCZCHEADER); 

    return error;
}

static void __exit H08module_exit(void)
{
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
    kobject_put(H08module);
}

module_init(H08module_init);
module_exit(H08module_exit);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
