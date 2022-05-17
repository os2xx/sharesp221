/* 
 * hello-5.c - Demonstrates command line argument passing to a module. 
 */ 
#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/moduleparam.h> 
#include <linux/stat.h> 

MODULE_AUTHOR("LKMPG team, modified by dewa251202");
MODULE_LICENSE("GPL"); 
MODULE_VERSION("REV02");
MODULE_DESCRIPTION("hello03");

static short int myshort = 1; 
static int myint = 1234; 
static long int mylong = 567890; 
static char *mystring = "This is mystring"; 
static int myintArray[5] = { -1, -1, -1, -1, -1 }; 
static int arr_argc = 0; 

#define prefix "ZCZC M03 "
 
/* module_param(foo, int, 0000) 
 * The first param is the parameters name. 
 * The second param is its data type. 
 * The final argument is the permissions bits, 
 * for exposing parameters in sysfs (if non-zero) at a later stage. 
 */ 
module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP); 
MODULE_PARM_DESC(myshort, "ShortInteger"); 
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
MODULE_PARM_DESC(myint, "Integer"); 
module_param(mylong, long, S_IRUSR); 
MODULE_PARM_DESC(mylong, "LongInteger"); 
module_param(mystring, charp, 0000); 
MODULE_PARM_DESC(mystring, "MyString"); 
 
/* module_param_array(name, type, num, perm); 
 * The first param is the parameter's (in this case the array's) name. 
 * The second param is the data type of the elements of the array. 
 * The third argument is a pointer to the variable that will store the number 
 * of elements of the array initialized by the user at module loading time. 
 * The fourth argument is the permission bits. 
 */ 
module_param_array(myintArray, int, &arr_argc, 0000); 
MODULE_PARM_DESC(myintArray, "Array[int]"); 
 
static int __init hello03_init(void) 
{ 
    int i; 
 
    pr_info(prefix "hello03 START\n"); 
    pr_info(prefix "myshort short integer: %hd\n", myshort); 
    pr_info(prefix "myint integer: %d\n", myint); 
    pr_info(prefix "mylong long integer: %ld\n", mylong); 
    pr_info(prefix "mystring: %s\n", mystring); 
 
    for (i = 0; i < ARRAY_SIZE(myintArray); i++) 
        pr_info(prefix "myintArray[%d] = %d\n", i, myintArray[i]); 
 
    pr_info(prefix "myintArray %d argc\n", arr_argc); 
    return 0; 
} 
 
static void __exit hello03_exit(void) 
{ 
    pr_info(prefix "hello03 STOP\n"); 
} 
 
module_init(hello03_init); 
module_exit(hello03_exit);
