/*
 * hello03.c - Kernel param.
 */
#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/moduleparam.h> 
#include <linux/stat.h> 

static short int myshort = 1; 
static int myint = 420; 
static long int mylong = 9999; 
static char *mystring = "blah"; 
static int myintarray[2] = { 420, 420 }; 
static int arr_argc = 0; 

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

static int _init_3(void)
{
    int i;
    pr_info("ZCZC M03 hello03 START\n");
    pr_info("ZCZC M03 myshort short integer: %hd\n", myshort); 
    pr_info("ZCZC M03 myint integer: %d\n", myint); 
    pr_info("ZCZC M03 mylong long integer: %ld\n", mylong); 
    pr_info("ZCZC M03 mystring string: %s\n", mystring);
    for (i = 0; i < ARRAY_SIZE(myintarray); i++) 
        pr_info("ZCZC M03 myintarray[%d]: %d\n", i, myintarray[i]);
    pr_info("ZCZC M03 myintArray %d argc", arr_argc);
    return 0;
}

static void _exit_3(void)
{
    pr_info("ZCZC M03 hello03 STOP\n");
}

module_init(_init_3);
module_exit(_exit_3);
MODULE_LICENSE("GPL");
