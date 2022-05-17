/*
 * hello-sysfs.c sysfs example
 */
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kobject.h>
#include <linux/module.h>
#include <linux/string.h>
#include <linux/sysfs.h>

#define prefix "ZCZC M08 "

static struct kobject *H08module;

/* the variable you want to be able to change */
static int hello08var = 0;

static ssize_t hello08var_show(struct kobject *kobj,
                               struct kobj_attribute *attr, char *buf)
{
    pr_info(prefix "/sys/kernel/H08module/hello08var = %d\n", hello08var);
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

    //pr_info("H08module: initialised\n");
    pr_info(prefix "hello08 START\n");

    H08module = kobject_create_and_add("H08module", kernel_kobj);
    if (!H08module)
        return -ENOMEM;

    error = sysfs_create_file(H08module, &hello08var_attribute.attr);
    if (error) {
        pr_info(prefix "failed to create the hello08var file "
                       "in /sys/kernel/H08module\n");
    }

    pr_info(prefix "/sys/kernel/H08module/hello08var [OK]\n");
    return error;
}

static void __exit H08module_exit(void)
{
    //pr_info("H08module: Exit success\n");
    kobject_put(H08module);
    pr_info(prefix "hello08 STOP\n");
}

module_init(H08module_init);
module_exit(H08module_exit);

MODULE_AUTHOR("LKMPG team, modified by dewa251202");
MODULE_LICENSE("GPL");
MODULE_VERSION("REV02");
MODULE_DESCRIPTION("hello08");
