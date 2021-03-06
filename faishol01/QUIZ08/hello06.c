/* 
 * procfs1.c 
 */ 
 
#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/proc_fs.h> 
#include <linux/uaccess.h> 
#include <linux/version.h> 

#define ZCZCHEADER  "ZCZC M06"
#define DESCRIPTION "hello06"
#define AUTHOR      "faishol01"
#define LICENSE     "GPL"
#define VERSION     "REV00"

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0) 
#define HAVE_PROC_OPS 
#endif 

#define PROCFS_MAX_SIZE 1024 
#define procfs_name "buffer1k" 
 
static struct proc_dir_entry *our_proc_file; 


/* This structure hold information about the /proc file */
static struct proc_dir_entry *our_proc_file;

/* The buffer used to store character for this module */
static char procfs_buffer[PROCFS_MAX_SIZE];

/* The size of the buffer */
static unsigned long procfs_buffer_size = 0;
 
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

/* This function is called with the /proc file is written. */ 
static ssize_t procfile_write(struct file *file, const char __user *buff, 
                              size_t len, loff_t *off) 
{ 
    procfs_buffer_size = len; 
    if (procfs_buffer_size > PROCFS_MAX_SIZE) 
        procfs_buffer_size = PROCFS_MAX_SIZE; 
 
    if (copy_from_user(procfs_buffer, buff, procfs_buffer_size)) 
        return -EFAULT; 
 
    procfs_buffer[procfs_buffer_size & (PROCFS_MAX_SIZE - 1)] = '\0'; 
    pr_info("%s procfile write %s\n", ZCZCHEADER, procfs_buffer); 
 
    return procfs_buffer_size; 
} 
 
#ifdef HAVE_PROC_OPS 
static const struct proc_ops proc_file_fops = { 
    .proc_read = procfile_read,
    .proc_write = procfile_write,
}; 
#else 
static const struct file_operations proc_file_fops = { 
    .read = procfile_read, 
    .write = procfile_write,
}; 
#endif 
 
static int __init procfs1_init(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    our_proc_file = proc_create(procfs_name, 0644, NULL, &proc_file_fops); 
    if (NULL == our_proc_file) { 
        proc_remove(our_proc_file); 
        pr_alert("Error:Could not initialize /proc/%s\n", procfs_name); 
        return -ENOMEM; 
    } 

    pr_info("%s /proc/%s created\n", ZCZCHEADER, procfs_name); 
    return 0; 
} 
 
static void __exit procfs1_exit(void) 
{ 
    proc_remove(our_proc_file); 
    pr_info("%s /proc/%s removed\n", ZCZCHEADER, procfs_name); 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
} 
 
module_init(procfs1_init); 
module_exit(procfs1_exit);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
