#include "ft_btree.h"

int	get_data(void)
{
	static int	i = 0;

	return (i++);
}

t_btree	*ft_make_prefix(int n, int *array)
{
	t_btree	*newtree;
	int		nl, nr;

	if (n == 0)
		return (NULL);
	else
	{
		nl = n / 2;
		nr = n - nl - 1;
		newtree = btree_create_node(&array[get_data()]);
		if (newtree == NULL)
		{
			puts("malloc error");
			return (NULL);
		}
		newtree->left = ft_make_prefix(nl, array);
		newtree->right = ft_make_prefix(nr, array);
		return (newtree);
	}
}

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

void	ft_print_int_item(void *item)
{
	int	*a;

	a = (int*)item;
	printf("%d\n", *a);
}

// void	ft_print_tree(t_btree *tree)
// {
// 	printf("left %p, right %p\n", tree->left, tree->right);
// }

void	 btree_apply_suffix(t_btree *root, void (*applyf)(void*))
{
	if (root == NULL)
		return ;
	if (root->left != NULL)
		btree_apply_suffix(root->left, applyf);
	// ft_print_tree(root);
	if (root->right != NULL)
		btree_apply_suffix(root->right, applyf);
	applyf(root->item);
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
	int		array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

	root = ft_make_prefix(13, array);
	print_tree(root, 0);
	btree_apply_suffix(root, ft_print_int_item);
	return (0);
}