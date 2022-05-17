#define VERSION "REV01"
// REV02: Thu 17 May 2022 13:25:00 WIB
// START: Mon 04 Apr 2022 17:00:00 WIB

#define ZCZCHEADER  "ZCZC M09"
#define DESCRIPTION "hello09, simplefs"
#define AUTHOR      "WhReen, referencing cbkadal's & LinuxCourses's"
#define LICENSE     "GPL"

#define pr_fmt(fmt) ZCZCHEADER KBUILD_MODNAME ": " fmt

#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */
#include <linux/init.h>
#include <linux/fs.h>

static int simplefs_readdir(struct file *filp, void *dirent, filldir_t filldir)
{
    /* ls will list nothing as of now.
     * Basic skeleton code to make ls (readdir) work for simplefs */
    return 0;
}

const struct file_operations simplefs_dir_operations = {
    .owner = THIS_MODULE,
    .readdir = simplefs_readdir,
};

struct dentry *simplefs_lookup(struct inode *parent_inode,
                   struct dentry *child_dentry, unsigned int flags)
{
    /* The lookup function is used for dentry association.
     * As of now, we don't deal with dentries in simplefs.
     * So we will keep this simple for now and revisit later */
    return NULL;
}

static struct inode_operations simplefs_inode_ops = {
    .lookup = simplefs_lookup,
};



struct inode *simplefs_get_inode(struct super_block *sb,
				 const struct inode *dir, umode_t mode,
				 dev_t dev)
{
    struct inode *inode = new_inode(sb);

    if (inode) {
        inode->i_ino = get_next_ino();
        inode_init_owner(inode, dir, mode);

        inode->i_atime = inode->i_mtime = inode->i_ctime = CURRENT_TIME;

        switch (mode & S_IFMT) {
        case S_IFDIR:
            /* i_nlink will be initialized to 1 in the inode_init_always function
             * (that gets called inside the new_inode function),
             * We change it to 2 for directories, for covering the "." entry */
            inc_nlink(inode);
            break;
        case S_IFREG:
        case S_IFLNK:
        default:
            printk(KERN_ERR
                "simplefs can create meaningful inode for only root directory at the moment\n");
            return NULL;
            break;
        }
    }
    return inode;
}

int simplefs_fill_super(struct super_block *sb, void *data, int silent)
{
    struct inode *inode;

    /* A magic number that uniquely identifies our filesystem type */
    sb->s_magic = 0x10032013;

    inode = simplefs_get_inode(sb, NULL, S_IFDIR, 0);
    inode->i_op = &simplefs_inode_ops;
    inode->i_fop = &simplefs_dir_operations;
    sb->s_root = d_make_root(inode);
    if (!sb->s_root)
        return -ENOMEM;

    return 0;
}

static struct dentry *simplefs_mount(struct file_system_type *fs_type,
                     int flags, const char *dev_name,
                     void *data)
{
    struct dentry *ret;

    ret = mount_bdev(fs_type, flags, dev_name, data, simplefs_fill_super);

    if (unlikely(IS_ERR(ret)))
        printk(KERN_ERR "Error mounting simplefs");
    else
        printk(KERN_INFO "simplefs is succesfully mounted on [%s]\n",
               dev_name);

    return ret;
}

static void simplefs_kill_superblock(struct super_block *s)
{
    printk(KERN_INFO
           "simplefs superblock is destroyed. Unmount succesful.\n");
    /* This is just a dummy function as of now. As our filesystem gets matured,
     * we will do more meaningful operations here */
    return;
}

struct file_system_type simplefs_fs_type = {
    .owner = THIS_MODULE,
    .name = "simplefs",
    .mount = simplefs_mount,
    .kill_sb = simplefs_kill_superblock,
};


static int __init hello09_start(void)
{
    int ret;

    ret = register_filesystem(&simplefs_fs_type);
    if (likely(ret == 0))
        printk(KERN_INFO "Sucessfully registered simplefs\n");
    else
        printk(KERN_ERR "Failed to register simplefs. Error:[%d]", ret);

    return ret;
    pr_info("%s - %s\n", DESCRIPTION, "START");
    /* A non 0 return means init_module failed; module can't be loaded. */
    return 0;
}

static void __exit hello09_end(void)
{
    int ret;

    ret = unregister_filesystem(&simplefs_fs_type);

    if (likely(ret == 0))
        printk(KERN_INFO "Sucessfully unregistered simplefs\n");
    else
        printk(KERN_ERR "Failed to unregister simplefs. Error:[%d]",
               ret);

    pr_info("%s - %s\n", DESCRIPTION, "STOP");
}

module_init(hello09_start);
module_exit(hello09_end);

MODULE_LICENSE(LICENSE);
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_VERSION(VERSION);
