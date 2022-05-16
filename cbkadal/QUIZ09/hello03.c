#define VERSION     "REV04"
// REV04: Sun 15 May 2022 11:00:00 WIB
// REV03: Mon 18 Apr 2022 22:30:00 WIB
// REV02: Tue 05 Apr 2022 13:00:00 WIB
// REV01: Mon 04 Apr 2022 11:30:00 WIB
// START: Sun 03 Apr 2022 15:00:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.

#define ZCZCHEADER  "ZCZC M03 "
#define DESCRIPTION "A module with init_module()/clean_module()"
#define AUTHOR      "Based on the LKMPG book, modified by C. BinKadal"
#define LICENSE     "GPL-2"

#define pr_fmt(fmt) ZCZCHEADER KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

// module_param(name, dataType, permissionBits)
// dataType: byte short ushort int uint long ulong charp bool invbool
static short int myshort = 1;
module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "ShortInteger");

static int         myint = 1234;
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "Integer");

static long int   mylong = 567890;
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "LongInteger");

static char    *mystring = "This is mystring";
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "MyString");

// module_param_array(name, dataType, numberPTR, permissionBits)
static int myintArray[5] = {-1,-1,-1,-1,-1};
static int      arr_argc = 0;
module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintArray, "Array[int]");

static int __init hello03_start(void) {
    pr_info("%s - %s\n",  DESCRIPTION, "START");
    pr_info("%s: %hd\n",  "myshort short integer", myshort);
    pr_info("%s: %d\n",   "myint integer", myint);
    pr_info("%s: %ld\n",  "mylong long integer", mylong);
    pr_info("%s: %s\n",   "mystring", mystring);
    for (int ii=0; ii<(sizeof myintArray / sizeof (int)); ii++) {
        pr_info("%s[%d]: %d\n", "myintArray", ii, myintArray[ii]);
    }
    pr_info("%s %d argc.\n", "myintArray", arr_argc);
    return 0;
}

static void __exit hello03_end(void) {
    pr_info("%s - %s\n",    DESCRIPTION, "STOP");
}

module_init(hello03_start);
module_exit(hello03_end);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

