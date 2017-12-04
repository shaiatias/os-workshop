#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("SHAI ATIAS");
MODULE_DESCRIPTION("Simple hello world module");

#define NULL = 0;

typedef struct Node {
	int info;
	Node* next;
}

static Node* root = NULL;

static void print_list()
{
	Node* item = root;

	while (item != NULL) {
		printk(KERN_INFO "printing item %d \n", item->info);
		item = item->next;
	} 
}

static void remove_from_list()
{
	Node* item = root;
	
	if (item->next == NULL)
	{
		return;
	}

	while (item->next != NULL) {
		item = item->next;
	}

	item->next = NULL;
}

static int __init hello_init(void)
{
	printk(KERN_INFO "hello from shai.\n");

	root = kmalloc(sizeof(Node));
	root->info = 1;

	root->next = kmalloc(sizeof(Node));
	root->next->info = 2;
	
	root->next->next = kmalloc(sizeof(Node));
	root->next->next->info = 3;

	root->next->next->next = kmalloc(sizeof(Node));
	root->next->next->next->info = 4;

	root->next->next->next->next = NULL;

	print_list();

	return 0;
}

static void __exit hello_cleanup(void)
{
	printk(KERN_INFO "cleanup work\n");
	
	remove_from_list();
	print_list();
}

module_init(hello_init);
module_exit(hello_cleanup);

