/*
 * hello02b.c - separate module.
 */
#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */

void _exit_2(void)
{
    pr_info("ZCZC M02 hello02 STOP\n");
}

module_exit(_exit_2);