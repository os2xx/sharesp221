/*
 * hello04.c
 */
#define VERSION     "REV03"
// REV03: Thu 19 May 2022 16:50:00 WIB
// REV02: Tue 17 May 2022 14:50:00 WIB
// REV01: Tue 10 May 2022 14:50:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M04"
#define DESCRIPTION "The /proc File System"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"
#define procfs_name "helloworld"
#define procfs_dir "/proc/" procfs_name

#define pr_fmt(fmt) ZCZCHEADER " " KBUILD_MODNAME ": " fmt

#include <linux/kernel.h> 
#include <linux/module.h> 
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
    char s[13] = "Hello World!\n"; 
    int len = sizeof(s); 
    ssize_t ret = len; 
 
    if (*offset >= len || copy_to_user(buffer, s, len)) { 
        pr_info("%s copy_to_user failed\n", procfs_dir); 
        ret = 0; 
    } else { 
        pr_info("%s read\n", procfs_dir); 
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
    pr_info("%s - %s\n", DESCRIPTION, "START");
    our_proc_file = proc_create(procfs_name, 0644, NULL, &proc_file_fops); 
    if (NULL == our_proc_file) { 
        proc_remove(our_proc_file); 
        pr_alert("Error:Could not initialize /proc/%s\n", procfs_name); 
        return -ENOMEM; 
    } 
 
    pr_info("%s created\n", procfs_dir); 
    return 0; 
} 
 
static void __exit procfs1_exit(void) 
{ 
    proc_remove(our_proc_file); 
    pr_info("%s removed\n", procfs_dir); 
    pr_info("%s - %s\n", DESCRIPTION, "STOP");
} 
 
module_init(procfs1_init); 
module_exit(procfs1_exit); 

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
