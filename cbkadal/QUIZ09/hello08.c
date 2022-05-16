#define VERSION     "REV04"
// REV04: Sun 15 May 2022 13:00:00 WIB
// REV03: Sat 07 May 2022 14:00:00 WIB
// REV02: Thu 05 May 2022 23:30:00 WIB
// REV01: Mon 25 Apr 2022 22:30:00 WIB
// START: Mon 04 Apr 2022 17:00:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.

#define ZCZCHEADER  "ZCZC M08 "
#define DESCRIPTION "/sys/ the sysfs"
#define AUTHOR      "Based on the LKMPG book, modified by C. BinKadal"
#define LICENSE     "GPL"

#define pr_fmt(fmt) ZCZCHEADER KBUILD_MODNAME ": " fmt

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
    pr_info("/sys/kernel/H08module/hello08var = %d\n", hello08var);
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

static int __init hello08_start(void) {
    int error = 0;

    pr_info("%s - %s\n", DESCRIPTION, "START");

    H08module = kobject_create_and_add("H08module", kernel_kobj);
    if (!H08module)
        return -ENOMEM;

    error = sysfs_create_file(H08module, &hello08var_attribute.attr);
    if (error) {
        pr_info("failed to create the hello08var file "
                "in /sys/kernel/H08module\n");
    } else {
        pr_info("/sys/kernel/H08module/hello08var [OK]\n");
    }

    return error;
}

static void __exit hello08_end(void) {
    kobject_put(H08module);
    pr_info("%s - %s\n", DESCRIPTION, "STOP");
}

module_exit(hello08_end);
module_init(hello08_start);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

