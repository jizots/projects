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

int	ft_intcmp(void *a, void *b)
{
	int *na;
	int *nb;

	na = (int*)a;
	nb = (int*)b;

	return (*na - *nb);
}

void	ft_print_tree(t_btree *tree)
{
	int	*a;

	a = (int*)tree->item;
	printf("data %d  left %p, right %p\n", *a, tree->left, tree->right);
}

t_btree	 *btree_search_item(t_btree *root, void *data_ref, int (*compf)(void*, void*))
{
	t_btree	*reroot;

	if (root == NULL)
		return (NULL);
	reroot = btree_search_item(root->left, data_ref, compf);
	if (compf(root->item, data_ref) == 0)
		return (root);
	if (reroot != NULL && compf(reroot->item, data_ref) == 0)
		return (reroot);
	ft_print_tree(root);
	reroot = btree_search_item(root->right, data_ref, compf);
	if (reroot != NULL && compf(reroot->item, data_ref) == 0)
		return (reroot);
	return (NULL);
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
	t_btree *result;
	int		array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	int		data =100;

	root = ft_make_prefix(13, array);
	print_tree(root, 0);
	result = btree_search_item(root, &data, ft_intcmp);
	if (result == NULL)
	{
		puts("no rusult");
		return (1);
	}
	int	*a;

	a = (int*)result->item;
	printf("%d\n", *a);
	free_tree(root);

	return (0);
}