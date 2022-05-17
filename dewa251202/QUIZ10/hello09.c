#include <linux/kernel.h> /* Needed for pr_info() */ 
#include <linux/module.h> /* Needed by all modules */ 
#include <linux/version.h>
#include <linux/fs.h>

#include "simplefs.h"

#define prefix "ZCZC M09 "

/* === fs.c === */

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

    pr_info("unmounted disk\n");
}

static struct file_system_type simplefs_file_system_type = {
    .owner = THIS_MODULE,
    .name = "simplefs",
    .mount = simplefs_mount,
    .kill_sb = simplefs_kill_sb,
    .fs_flags = FS_REQUIRES_DEV,
    .next = NULL,
};

static int __init init_hello09(void) 
{
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

    pr_info(prefix "hello09 START\n"); 

    /* A non 0 return means init_module failed; module can't be loaded. */ 
end:
    return ret; 
} 

static void __exit exit_hello09(void) 
{ 
    int ret = unregister_filesystem(&simplefs_file_system_type);
    if (ret)
        pr_err("unregister_filesystem() failed\n");

    simplefs_destroy_inode_cache();

    pr_info(prefix "hello09 STOP\n"); 
} 

module_init(init_hello09);
module_exit(exit_hello09);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GSGS & dewa251202");
MODULE_VERSION("REV04");
MODULE_DESCRIPTION("A module for simplefs");
