//http://www.thegeekstuff.com/2013/07/write-linux-kernel-module/?utm_source=tuicool

#include <stdout.h>
#include <stdlib.h>

typedef struct Node {
	int info;
	struct Node *next;
} Node;

static Node *root = NULL;

void print_list(void)
{
	Node *item = root;

	while (item != NULL) {
	 	printf("printing item %d \n", item->info);
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

	while (item->next != NULL && item->next->next != NULL) {
		item = item->next;
	}

	item->next = NULL;
}


static int main(void)
{
	printf("hello from shai.\n");

	root = (struct Node *) malloc(sizeof(struct Node));
	root->info = 1;

	root->next = (struct Node *) malloc(sizeof(struct Node));
	root->next->info = 2;

	root->next->next = (struct Node *) malloc(sizeof(struct Node));
	root->next->next->info = 3;

	root->next->next->next = (struct Node *) malloc(sizeof(struct Node));
	root->next->next->next->info = 4;

	root->next->next->next->next = NULL;

	// print list after initial state
	print_list();

	return 0;
}

static void __exit hello_cleanup(void)
{
	printf("cleanup work\n");

	// remove item from list
	remove_from_list();

	// print list after remove item
	print_list();

	// free memory
	free(root);
}
