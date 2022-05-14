#define VERSION     "REV02"
#define ZCZCHEADER  "ZCZC M03"
#define DESCRIPTION "hello03"
#define AUTHOR      "efsrdi"
#define LICENSE     "GPL"

#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/moduleparam.h> 
#include <linux/stat.h> 

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

static int __init hello_3_init(void)
{
    int i;
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    pr_info("%s myshort short integer: %hd\n", ZCZCHEADER, myshort); 
    pr_info("%s myint integer: %d\n", ZCZCHEADER, myint); 
    pr_info("%s mylong long integer: %ld\n", ZCZCHEADER, mylong); 
    pr_info("%s mystring: %s\n", ZCZCHEADER, mystring);
    for (i = 0; i < ARRAY_SIZE(myintArray); i++) 
	if (arr_argc != 0)
        	pr_info("%s myintArray[%d]: %d\n", ZCZCHEADER, i, myintArray[i]);
	else
		pr_info("%s myintArray[%d]: %s\n", ZCZCHEADER, i, "-1");
    pr_info("%s myintArray %d argc\n", ZCZCHEADER, arr_argc);
    return 0;
}

static void __exit hello_3_exit(void)
{
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

module_init(hello_3_init);
module_exit(hello_3_exit);
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_LICENSE(LICENSE);
MODULE_VERSION(VERSION);
