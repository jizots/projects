#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*newnode;

	newnode = malloc(sizeof(t_btree));
	if (newnode == NULL)
		return (NULL);
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->item = item;
	return (newnode);
}

// int	main(void)
// {
// 	int	a = 42;
// 	int *item;
// 	t_btree	*node;

// 	node = btree_create_node(&a);
// 	item = (int*)node->item;
// 	printf("%d\n", *item);
// }