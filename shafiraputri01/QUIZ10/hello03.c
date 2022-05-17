/*
 * hello03.c
 */
#define VERSION     "REV02"
// REV02: Tue 17 May 2022 14:50:00 WIB
// REV01: Tue 10 May 2022 14:50:00 WIB
// (c) 2022-2022 It is a FREE GSGS one.
#define ZCZCHEADER  "ZCZC M03"
#define DESCRIPTION "A module with init_module()/clean_module()"
#define AUTHOR      "shafiraputri01"
#define LICENSE     "GPL"

#define pr_fmt(fmt) ZCZCHEADER " " KBUILD_MODNAME ": " fmt

#include <linux/kernel.h> /* We are doing kernel work */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h> 

static short int myshort = 1; 
static int myint = 1234; 
static long int mylong = 567890; 
static char *mystring = "This is mystring"; 
static int myintArray[5] = {}; 
static int arr_argc = 0; 
 
module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP); 
MODULE_PARM_DESC(myshort, "ShortInteger"); 
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
MODULE_PARM_DESC(myint, "Integer"); 
module_param(mylong, long, S_IRUSR); 
MODULE_PARM_DESC(mylong, "LongInteger"); 
module_param(mystring, charp, 0000); 
MODULE_PARM_DESC(mystring, "MyString"); 
 
module_param_array(myintArray, int, &arr_argc, 0000); 
MODULE_PARM_DESC(myintArray, "Array[int]"); 

static int h_init(void)
{
    int i;
    pr_info(%s - %s\n", DESCRIPTION, "START");

    pr_info("myshort short integer: %hd\n", myshort);
    pr_info("myint integer: %d\n", myint);
    pr_info("mylong long integer: %ld\n", mylong);
    pr_info("mystring: %s\n",, mystring);

    for (i = 0; i < ARRAY_SIZE(myintArray); i++) 
        if (arr_argc != 0)
            pr_info("myintArray[%d]: %d\n", i, myintArray[i]);
        else
            pr_info("myintArray[%d]: %s\n", i, "-1");

    pr_info("myintArray %d argc\n", arr_argc);
 
    return 0;
}

void h_exit(void)
{
    pr_info("%s - %s\n", DESCRIPTION, "STOP");
}

module_init(h_init);
module_exit(h_exit);

MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);

