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

size_t	ft_locate_maximum(t_list *root)
{
	int		max;
	size_t	locate;
	size_t	i;

	max = *(root->cont);
	locate = 0;
	i = 0;
	while (root->cont != NULL)
	{
		if (max < *(root->cont))
		{
			max = *(root->cont);
			locate = i;
		}
		root = root->next;
		i++;
	}
	return (locate);
}

void	ft_sort_int_exec(int *list_int, size_t size_list)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	while (i < size_list - 1)
	{
		j = i + 1;
		while (j < size_list)
		{
			if (list_int[i] > list_int[j])
			{
				tmp = list_int[i];
				list_int[i] = list_int[j];
				list_int[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*ft_sort_int(t_list *list)
{
	int		*list_int;
	size_t	i;
	size_t	size_list;

	size_list = ft_lstsize(list);
	list_int = malloc(sizeof(int) * size_list);
	if (list_int == NULL)
		return (NULL);
	i = 0;
	while (list->cont != NULL)
	{
		list_int[i++] = *(list->cont);
		list = list->next;
	}
	ft_sort_int_exec(list_int, size_list);
	return (list_int);
}