#define VERSION     "START"
// START: Tue 17 May 2022 14:50:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M09"
#define DESCRIPTION "A simple file system"
#define AUTHOR      "National Cheng Kung University, Taiwan, editted by shafiraputri01"
#define LICENSE     ""Dual BSD/GPL"

#define pr_fmt(fmt) ZCZCHEADER " " KBUILD_MODNAME ": " fmt


#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include "simplefs.h"

/* Mount a simplefs partition */
struct dentry *simplefs_mount(struct file_system_type *fs_type,
                              int flags,
                              const char *dev_name,
                              void *data)
{
    struct dentry *dentry =
        mount_bdev(fs_type, flags, dev_name, data, simplefs_fill_super);
    if (IS_ERR(dentry))
        pr_err("'%s' mount failure\n", dev_name);
    else
        pr_info("'%s' mount success\n", dev_name);

    return dentry;
}

/* Unmount a simplefs partition */
void simplefs_kill_sb(struct super_block *sb)
{
    kill_block_super(sb);

    pr_info("unmount success\n");
}

static struct file_system_type simplefs_file_system_type = {
    .owner = THIS_MODULE,
    .name = "simplefs",
    .mount = simplefs_mount,
    .kill_sb = simplefs_kill_sb,
    .fs_flags = FS_REQUIRES_DEV,
    .next = NULL,
};

static int __init simplefs_init(void)
{
    pr_info("%s - %s\n", DESCRIPTION, "START");
    int ret = simplefs_init_inode_cache();
    if (ret) {
        pr_err("inode cache creation failed\n");
        goto end;
    }

    ret = register_filesystem(&simplefs_file_system_type);
    if (ret) {
        pr_err("register_filesystem() failed\n");
        goto end;
    }

    pr_info("%s\n", ZCZCHEADER, "Module loaded");
end:
    return ret;
}

static void __exit simplefs_exit(void)
{
    int ret = unregister_filesystem(&simplefs_file_system_type);
    if (ret)
        pr_err("unregister_filesystem() failed\n");

    pr_info("%s\n", "Module unloaded");

    pr_info("%s - %s\n", DESCRIPTION, "STOP");
}

module_init(simplefs_init);
module_exit(simplefs_exit);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
