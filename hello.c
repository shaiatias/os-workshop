#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("SHAI ATIAS");
MODULE_DESCRIPTION("Simple hello world module");

static int __init hello_init(void)
{
	printk(KERN_INFO "hello from shai.\n");
	return 0;
}

static void __exit hello_cleanup(void)
{
	printk(KERN_INFO "cleanup work\n");
}

module_init(hello_init);
module_exit(hello_cleanup);

