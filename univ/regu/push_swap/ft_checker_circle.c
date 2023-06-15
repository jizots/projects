#include "push_swap.h"

size_t	ft_ascending_circle(t_list *root)
{
	int		min;
	size_t	i;
	size_t	locate_min;

	min = *(root->cont);
	i = 0;
	locate_min = 0;
	while (root->cont != NULL)
	{
		if (ft_inta_is_small(root->cont, root->next->cont) == -1)
		{
			locate_min = i + 1;
			root = root->next;
			while (root->cont != NULL)
			{
				if (min < *(root->cont) || ft_inta_is_small(root->cont, root->next->cont) == -1)
					return (0);
				root = root->next;
			}
			return (locate_min);
		}
		root = root->next;
		i++;
	}
	return (locate_min);
}

size_t	ft_descending_circle(t_list *root)
{
	int		max;
	size_t	i;
	size_t	locate_max;

	max = *(root->cont);
	i = 0;
	locate_max = 0;
	while (root->cont != NULL)
	{
		if (ft_intb_is_small(root->cont, root->next->cont) == -1)
		{
			locate_max = i + 1;
			root = root->next;
			while (root->cont != NULL)
			{
				if (max > *(root->cont) || ft_intb_is_small(root->cont, root->next->cont) == -1)
					return (0);
				root = root->next;
			}
			return (locate_max);
		}
		root = root->next;
		i++;
	}
	return (locate_max);
}