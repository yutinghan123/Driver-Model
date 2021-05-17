#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
static int hello_init(void)
{
	printk("Hello Module!\n");
	return 0;
}
static void exit_init(void)
{
	printk("Exit Module!\n");
}
MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(exit_init);

