#define VERSION     "REV04"
// REV04: Sun 15 May 2022 12:30:00 WIB
// REV03: Sat 14 May 2022 17:00:00 WIB
// REV02: Sun 01 May 2022 23:30:00 WIB
// REV01: Mon 18 Apr 2022 23:00:00 WIB
// START: Mon 04 Apr 2022 17:00:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.

#define ZCZCHEADER  "ZCZC M04 "
#define DESCRIPTION "The /proc File System"
#define AUTHOR      "Based on the LKMPG book, modified by C. BinKadal"
#define LICENSE     "GPL-2"
#define PROCFS_NAME "helloworld"

#define pr_fmt(fmt) ZCZCHEADER KBUILD_MODNAME ": " fmt

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/version.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0)
#define HAVE_PROC_OPS
#endif

static struct proc_dir_entry *our_proc_file;

static ssize_t procfile_read(struct file *filePointer, char __user *buffer,
                             size_t buffer_length, loff_t *offset)
{
    char s[14] = "Hello World!\n";
    int len = sizeof(s);
    ssize_t ret = len;

    if (*offset >= len || copy_to_user(buffer, s, len)) {
        pr_info("/proc/%s copy_to_user failed\n", filePointer->f_path.dentry->d_name.name);
        ret = 0;
    } else {
        pr_info("/proc/%s read\n", filePointer->f_path.dentry->d_name.name);
        *offset += len;
    }

    return ret;
}

#ifdef HAVE_PROC_OPS
static const struct proc_ops proc_file_fops = {
    .proc_read = procfile_read,
};
#else
static const struct file_operations proc_file_fops = {
    .read = procfile_read,
};
#endif

static int __init procfs1_init(void)
{
    our_proc_file = proc_create(PROCFS_NAME, 0644, NULL, &proc_file_fops);
    if (NULL == our_proc_file) {
        proc_remove(our_proc_file);
        pr_info("Error:Could not initialize /proc/%s\n", PROCFS_NAME);
        return -ENOMEM;
    }

    pr_info("%s - %s\n",          DESCRIPTION, "START");
    pr_info("/proc/%s created\n", PROCFS_NAME);
    return 0;
}

static void __exit procfs1_exit(void)
{
    proc_remove(our_proc_file);
    pr_info("/proc/%s removed\n", PROCFS_NAME);
    pr_info("%s - %s\n",            DESCRIPTION, "STOP");
}

module_init(procfs1_init);
module_exit(procfs1_exit);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

