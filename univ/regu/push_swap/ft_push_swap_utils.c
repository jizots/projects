#include "push_swap.h"

int	ft_lstsize(t_list *list)
{
	int	value_return;

	if (list == NULL)
		return (0);
	value_return = 0;
	while (list->cont != NULL)
	{
		list = list->next;
		value_return++;
		if (value_return < 0)
			return (-1);
	}
	return (value_return);
}

size_t	ft_locate_minimum(t_list *root)
{
	int		min;
	size_t	locate;
	size_t	i;

	min = *(root->cont);
	locate = 0;
	i = 0;
	while (root->cont != NULL)
	{
		if (min > *(root->cont))
		{
			min = *(root->cont);
			locate = i;
		}
		root = root->next;
		i++;
	}
	return (locate);
}