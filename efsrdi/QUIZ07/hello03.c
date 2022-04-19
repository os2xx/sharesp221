#define ZCZCHEADER  "ZCZC M03"
#define DESCRIPTION "hello03"

#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/moduleparam.h> 
#include <linux/stat.h> 

static short int myshort = 69; 
static int myint = 888; 
static long int mylong = 1234567890; 
static char *mystring = "newString"; 
static int myintarray[5] = { 1, 2, 3, 4, 5 }; 
static int arr_argc = 5; 

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP); 
MODULE_PARM_DESC(myshort, "A short integer"); 
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
MODULE_PARM_DESC(myint, "An integer"); 
module_param(mylong, long, S_IRUSR); 
MODULE_PARM_DESC(mylong, "A long integer"); 
module_param(mystring, charp, 0000); 
MODULE_PARM_DESC(mystring, "A character string"); 

module_param_array(myintarray, int, &arr_argc, 0000); 
MODULE_PARM_DESC(myintarray, "An array of integers"); 

static int __init hello_3_init(void)
{
    int i;
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "START");
    pr_info("%s myshort short integer: %hd\n", ZCZCHEADER, myshort); 
    pr_info("%s myint integer: %d\n", ZCZCHEADER, myint); 
    pr_info("%s mylong long integer: %ld\n", ZCZCHEADER, mylong); 
    pr_info("%s mystring string: %s\n", ZCZCHEADER, mystring);
    for (i = 0; i < ARRAY_SIZE(myintarray); i++) 
        pr_info("%s myintarray[%d]: %d\n", ZCZCHEADER, i, myintarray[i]);
    pr_info("%s myintArray %d argc", ZCZCHEADER, arr_argc);
    return 0;
}

static void __exit hello_3_exit(void)
{
    pr_info("%s %s %s\n", ZCZCHEADER, DESCRIPTION, "STOP");
}

module_init(hello_3_init);
module_exit(hello_3_exit);
MODULE_LICENSE("GPL");
