#include "ft_btree.h"

void	print_tree(t_btree *t, int h)
{
	int	i;
	int	*a;

	if (t != NULL)
	{
		print_tree(t->right, h + 1);
		for (i = 0; i < h; i++)
		printf("\t");
		a = (int*)t->item;
		printf("%d\n", *a);
		print_tree(t->left, h + 1);
	}
}

int	ft_intcmp(void *a, void *b)
{
	int *na;
	int *nb;

	na = (int*)a;
	nb = (int*)b;

	if (*na < *nb)
		return (-1);
	else if (*na == *nb)
		return (0);
	else
		return (1);
}

void	 btree_insert_data(t_btree **root, void *data, int (*cmpf)(void*, void*))
{
	t_btree	*current;
	t_btree	*newnode;

	current = *root;
    if (current == NULL)
    {
        *root = btree_create_node(data);
        return;
    }
	if(cmpf(current->item, data) <= 0)
	{
		if (current->right == NULL)
		{
			newnode = btree_create_node(data);
			current->right = newnode;
		}
		else
			btree_insert_data(&(current->right), data, cmpf);
	}
	else
	{
		if (current->left == NULL)
		{
			newnode = btree_create_node(data);
			current->left = newnode;
		}
		else
			btree_insert_data(&(current->left), data, cmpf);
	}
}

void	free_tree(t_btree *root)
{
	if (root == NULL)
		return ;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

int	main(void)
{
	t_btree	*root;
	int	array[]={8, 3, 10, 1, 6, 4, 7, 14, 13};
	root = btree_create_node(&array[0]);
    root->left = btree_create_node(&array[1]);
    root->right = btree_create_node(&array[2]);
    root->left->left = btree_create_node(&array[3]);
    root->left->right = btree_create_node(&array[4]);
    root->left->right->left = btree_create_node(&array[5]);
    root->left->right->right = btree_create_node(&array[6]);
    root->right->right = btree_create_node(&array[7]);
    root->right->right->left = btree_create_node(&array[8]);

	print_tree(root, 0);
    printf("\n");

	//call main func
	int	data = 11;
	btree_insert_data(&root, &data, ft_intcmp);

	//verify main func
	print_tree(root, 0);

	//free allocated memory
    free_tree(root);

	return (0);
}