/*
 * hello03.c
 */

#include <linux/kernel.h> /* We are doing kernel work */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h> 

static short int myshort = 69; 
static int myint = 888; 
static long int mylong = 1234567890; 
static char *mystring = "newString"; 
static int myintarray[5] = { 1,2,3,4,5 }; 
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

static int h_init(void)
{
    pr_info("ZCZC M03 hello03 START\n");
    int i; 

    pr_info("Hello, world 5\n=============\n"); 
    pr_info("myshort is a short integer: %hd\n", myshort); 
    pr_info("myint is an integer: %d\n", myint); 
    pr_info("mylong is a long integer: %ld\n", mylong); 
    pr_info("mystring is a string: %s\n", mystring); 
 
    for (i = 0; i < ARRAY_SIZE(myintarray); i++) 
        pr_info("myintarray[%d] = %d\n", i, myintarray[i]);
 
    return 0;
}

void h_exit(void)
{
    pr_info("ZCZC M03 hello03 STOP\n");
}

module_init(h_init);
module_exit(h_exit);

MODULE_LICENSE("GPL");
