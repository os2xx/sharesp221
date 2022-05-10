/*
 * hello07.c
 */
#define VERSION     "START"
#define ZCZCHEADER  "ZCZC M07"
#define DESCRIPTION "hello07"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"

#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/version.h>
#include <linux/moduleparam.h> 

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0) 
#define HAVE_PROC_OPS 
#endif 
 
#define PROC_NAME "ITER"

static unsigned long int counter = 0; 
module_param(counter, ulong, 0000); 
MODULE_PARM_DESC(counter, "UnsignedLongInteger"); 

static void *my_seq_start(struct seq_file *s, loff_t *pos) 
{ 
    /* beginning a new sequence? */ 
    if (*pos == 0) { 
        /* yes => return a non null value to begin the sequence */ 
        return &counter; 
    } 
 
    /* no => it is the end of the sequence, return end to stop reading */ 
    *pos = 0; 
    return NULL; 
}

static void *my_seq_next(struct seq_file *s, void *v, loff_t *pos) 
{ 
    unsigned long *tmp_v = (unsigned long *)v; 
    (*tmp_v)++; 
    (*pos)++; 
    return NULL; 
}

static void my_seq_stop(struct seq_file *s, void *v) 
{ 
} 

static int my_seq_show(struct seq_file *s, void *v) 
{ 
    loff_t *spos = (loff_t *)v; 
    pr_info("%s %s %s=%Ld\n", ZCZCHEADER, PROC_NAME, "COUNTER", *spos);
    seq_printf(s, "%Ld\n", *spos); 
    return 0; 
} 
 
static struct seq_operations my_seq_ops = { 
    .start = my_seq_start, 
    .next = my_seq_next, 
    .stop = my_seq_stop, 
    .show = my_seq_show, 
}; 
 
static int my_open(struct inode *inode, struct file *file) 
{ 
    return seq_open(file, &my_seq_ops); 
}; 

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
    struct proc_dir_entry *entry;
    
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");

    entry = proc_create(PROC_NAME, 0, NULL, &my_file_ops);
    pr_info("%s /proc/%s %s\n", ZCZCHEADER, PROC_NAME, "created");
    if (entry == NULL) {
        remove_proc_entry(PROC_NAME, NULL);
        pr_debug("Error: Could not initialize /proc/%s\n", PROC_NAME);
        return -ENOMEM;
    }
    pr_info("%s unsigned long integer (COUNTER): %ld\n", ZCZCHEADER, counter);

    return 0; 
} 
 
static void __exit hello07_exit(void) 
{ 
    remove_proc_entry(PROC_NAME, NULL);
    pr_info("%s /proc/%s %s\n", ZCZCHEADER, PROC_NAME, "removed");
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
} 
 
module_init(hello07_init); 
module_exit(hello07_exit); 

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

