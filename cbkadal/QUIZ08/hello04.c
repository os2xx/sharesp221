#define VERSION     "REV02"
// REV02: Sun 01 May 2022 23:30:00 WIB
// REV01: Mon 18 Apr 2022 23:00:00 WIB
// START: Mon 04 Apr 2022 17:00:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M04"
#define DESCRIPTION "hello04"
#define procfs_name "helloworld"
#define AUTHOR      "Jim Huang, modified by C. BinKadal"
#define LICENSE     "GPL"

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
    char s[13] = "HelloWorld!\n";
    int len = sizeof(s);
    ssize_t ret = len;

    if (*offset >= len || copy_to_user(buffer, s, len)) {
        pr_info("%s copy_to_user failed\n", ZCZCHEADER);
        ret = 0;
    } else {
        pr_info("%s procfile read %s\n", ZCZCHEADER, filePointer->f_path.dentry->d_name.name);
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
    our_proc_file = proc_create(procfs_name, 0644, NULL, &proc_file_fops);
    if (NULL == our_proc_file) {
        proc_remove(our_proc_file);
        pr_alert("%s Error:Could not initialize /proc/%s\n", ZCZCHEADER, procfs_name);
        return -ENOMEM;
    }

    pr_info("%s %s %s\n",            ZCZCHEADER, DESCRIPTION, "START");
    pr_info("%s /proc/%s created\n", ZCZCHEADER, procfs_name);
    return 0;
}

static void __exit procfs1_exit(void)
{
    proc_remove(our_proc_file);
    pr_info("%s /proc/%s removed\n", ZCZCHEADER, procfs_name);
    pr_info("%s %s %s\n",            ZCZCHEADER, DESCRIPTION, "STOP");
}

module_init(procfs1_init);
module_exit(procfs1_exit);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

