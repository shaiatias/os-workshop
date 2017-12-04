#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("SHAI ATIAS");
MODULE_DESCRIPTION("Simple hello world module");

typedef struct Node {
	int info;
	struct Node *next;
} Node;

static Node *root = { 1, { 2, { 3, { 4, NULL} } } };

void print_list(void)
{
	Node *item = root;

	while (item != NULL) {
	 	printk(KERN_INFO "printing item %d \n", item->info);
	 	item = item->next;
	}
}

void remove_from_list(void)
{
	Node *item = root;

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

	// root = (struct Node *) kmalloc(sizeof(Node), GFP_KERNEL);
	// root->info = 1;

	// root->next = (struct Node *) kmalloc(sizeof(Node), GFP_KERNEL);
	// root->next->info = 2;

	// root->next->next = (struct Node *) kmalloc(sizeof(Node), GFP_KERNEL);
	// root->next->next->info = 3;

	// root->next->next->next = (struct Node *) kmalloc(sizeof(Node), GFP_KERNEL);
	// root->next->next->next->info = 4;

	// root->next->next->next->next = NULL;

	// print list after initial state
	print_list();

	return 0;
}

static void __exit hello_cleanup(void)
{
	printk(KERN_INFO "cleanup work\n");

	// remove item from list
	remove_from_list();

	// print list after remove item
	print_list();

	// free memory
	kfree(root);
}

module_init(hello_init);
module_exit(hello_cleanup);
