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

int	btree_level_count(t_btree *root)
{
	int	count_left;
	int	count_right;

	if (root == NULL)
		return (0);
	if (root->left == NULL && root->right == NULL)
		return (0);
	count_left = btree_level_count(root->left);
	count_right = btree_level_count(root->right);
	if (count_left >= count_right)
		return (count_left + 1);
	else
		return (count_right + 1);
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
	int		count_array = sizeof(array) / sizeof(int);

	root = ft_make_prefix(count_array, array);
	print_tree(root, 0);
	printf("%d\n", btree_level_count(root));
	free_tree(root);

	return (0);
}