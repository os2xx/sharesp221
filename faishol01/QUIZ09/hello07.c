#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/proc_fs.h> 
#include <linux/uaccess.h> 
#include <linux/version.h> 

#define ZCZCHEADER  "ZCZC M07"
#define DESCRIPTION "hello07"
#define AUTHOR      "faishol01"
#define LICENSE     "GPL"
#define VERSION     "REV00"


#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0) 
#define HAVE_PROC_OPS 
#endif 

#define PROCFS_MAX_SIZE 1024 
#define procfs_name "ITER" 



#ifdef HAVE_PROC_OPS 
static const struct proc_ops my_file_ops = { 
    .proc_open = my_open, 
    .proc_read = seq_read, 
    .proc_lseek = seq_lseek, 
    .proc_release = seq_release, 
}; 
#else 
static const struct file_operations my_file_ops = { 
    .open = my_open, 
    .read = seq_read, 
    .llseek = seq_lseek, 
    .release = seq_release, 
}; 
#endif 

static int __init hello07_init(void) 
{ 
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");

    struct proc_dir_entry *entry; 
    entry = proc_create(PROC_NAME, 0, NULL, &my_file_ops); 
    if (entry == NULL) { 
        remove_proc_entry(PROC_NAME, NULL); 
        pr_debug("Error: Could not initialize /proc/%s\n", PROC_NAME); 
        return -ENOMEM; 
    } 

    pr_info("%s /proc/%s created\n", ZCZCHEADER, PROC_NAME); 
    
    return 0; 
} 
 
static void __exit hello07_exit(void) 
{ 
    remove_proc_entry(PROC_NAME, NULL); 
    pr_debug("%s /proc/%s removed\n", ZCZCHEADER, PROC_NAME);
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
} 

module_init(hello07_init); 
module_exit(hello07_exit);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);