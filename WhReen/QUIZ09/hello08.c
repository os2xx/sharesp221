#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kobject.h>
#include <linux/module.h>
#include <linux/string.h>
#include <linux/sysfs.h>

#define ZCZCHEADER  "ZCZC M08"
#define DESCRIPTION "hello08"
#define AUTHOR      "WhReen"
#define LICENSE     "GPL"

static struct kobject *H08module;

/* the variable you want to be able to change */
static int hello08var = 0;

static ssize_t hello08var_show(struct kobject *kobj,
                               struct kobj_attribute *attr, char *buf)
{
    pr_info("ZCZC M08 /sys/kernel/H08module/hello08var [OK]\n");
    return sprintf(buf, "%d\n", hello08var);
}

static ssize_t hello08var_store(struct kobject *kobj,
                                struct kobj_attribute *attr, char *buf,
                                size_t count)
{
    sscanf(buf, "%du", &hello08var);
    pr_info("ZCZC M08 /sys/kernel/H08module/hello08var = $d\n", count);
    return count;
}

static struct kobj_attribute hello08var_attribute =
    __ATTR(hello08var, 0660, hello08var_show, (void *)hello08var_store);

static int _init_8(void)
{
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");

    int error = 0;

    H08module = kobject_create_and_add("H08module", kernel_kobj);
    if (!H08module)
        return -ENOMEM;

    error = sysfs_create_file(H08module, &hello08var_attribute.attr);
    if (error) {
        pr_info("failed to create the hello08var file "
                "in /sys/kernel/H08module\n");
    }

    return error;
}

static void _exit_8(void)
{
    kobject_put(H08module);
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

module_init(_init_8);
module_exit(_exit_8);
MODULE_LICENSE(LICENSE);
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
