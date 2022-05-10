#define ZCZCHEADER  "ZCZC M03"
#define DESCRIPTION "hello03"
#define AUTHOR      "Samuel"
#define LICENSE     "GPL"
#define VERSION     "REV00"

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

static short int myshort = 1;
static int myint = 1234;
static long int mylong = 567890;
static char *mystring = "This is mystring";
static int myintarray[5] = { -1, -1, -1, -1, -1 };
static int arr_argc = 0;

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "ShortInteger");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "Integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "LongInteger");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "MyString");
module_param_array(myintarray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintarray, "Array[int]");

static int __init hello03_init(void)
{
    int i;

    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");

    pr_info("%s myshort short integer: %hd\n", ZCZCHEADER, myshort);
    pr_info("%s myint integer: %d\n", ZCZCHEADER, myint);
    pr_info("%s mylong long integer: %ld\n", ZCZCHEADER, mylong);
    pr_info("%s mystring: %s\n", ZCZCHEADER, mystring);
    for (i = 0; i < ARRAY_SIZE(myintarray); i++)
        pr_info("%s myintarray[%d] = %d\n", ZCZCHEADER, i, myintarray[i]);
    pr_info("%s myintArray %d argc", ZCZCHEADER, arr_argc);
    return 0;
}

static void __exit hello03_exit(void)
{
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

module_init(hello03_init);
module_exit(hello03_exit);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
