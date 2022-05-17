#define VERSION     "REV03"
// REV03: Sun 15 May 2022 13:30:00 WIB
// REV02: Sat 07 May 2022 14:00:00 WIB
// REV01: Thu 05 May 2022 11:00:00 WIB
// START: Mon 04 Apr 2022 17:00:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.

#define ZCZCHEADER  "ZCZC M07 "
#define DESCRIPTION "/proc/ file with seq_file"
#define AUTHOR      "Based on the LKMPG book, modified by C. BinKadal"
#define LICENSE     "GPL-2"
#define PROC_NAME   "ITER"

#define pr_fmt(fmt) ZCZCHEADER KBUILD_MODNAME ": " fmt

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/version.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0)
#define HAVE_PROC_OPS
#endif

static unsigned long int counter = 0;
module_param(counter, ulong, S_IRUSR);
MODULE_PARM_DESC(counter, "UnsignedLongInteger");

/* This function is called at the beginning of a sequence.
 * ie, when:
 *   - the /proc file is read (first time)
 *   - after the function stop (end of sequence)
 */
static void *my_seq_start(struct seq_file *s, loff_t *pos)
{
    /* beginning a new sequence? */
    if (*pos == 0) {
        /* yes => return a non null value to begin the sequence */
        pr_info("ITER COUNTER=%ld\n", counter);
        return &counter;
    }

    /* no => it is the end of the sequence, return end to stop reading */
    *pos = 0;
    return NULL;
}

/* This function is called after the beginning of a sequence.
 * It is called untill the return is NULL (this ends the sequence).
 */
static void *my_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
    unsigned long *tmp_v = (unsigned long *)v;
    (*tmp_v)++;
    (*pos)++;
    return NULL;
}

/* This function is called at the end of a sequence. */
static void my_seq_stop(struct seq_file *s, void *v)
{
    /* nothing to do, we use a static value in start() */
}

/* This function is called for each "step" of a sequence. */
static int my_seq_show(struct seq_file *s, void *v)
{
    loff_t *spos = (loff_t *)v;

    seq_printf(s, "%Ld\n", *spos);
    return 0;
}

/* This structure gather "function" to manage the sequence */
static struct seq_operations my_seq_ops = {
    .start = my_seq_start,
    .next = my_seq_next,
    .stop = my_seq_stop,
    .show = my_seq_show,
};

/* This function is called when the /proc file is open. */
static int my_open(struct inode *inode, struct file *file)
{
    return seq_open(file, &my_seq_ops);
};

/* This structure gather "function" that manage the /proc file */
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

static int __init hello07_start(void) {
    struct proc_dir_entry *entry;

    entry = proc_create(PROC_NAME, 0, NULL, &my_file_ops);
    if (entry == NULL) {
        remove_proc_entry(PROC_NAME, NULL);
        pr_info("Error: Could not initialize /proc/%s\n", PROC_NAME);
        return -ENOMEM;
    }
    pr_info("%s - %s\n",            DESCRIPTION, "START");
    pr_info("/proc/%s created\n", PROC_NAME);
    pr_info("%s: %ld\n",          "unsigned long integer (COUNTER)", counter);
    return 0;
}

static void __exit hello07_end(void) {
    remove_proc_entry(PROC_NAME, NULL);
    pr_info("/proc/%s removed\n", PROC_NAME);
    pr_info("%s - %s\n",            DESCRIPTION, "STOP");
}

module_init(hello07_start);
module_exit(hello07_end);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

