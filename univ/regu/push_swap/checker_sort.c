#include "push_swap.h"

int	ft_inta_is_small(void *a, void *b)
{
	int	*av;
	int	*bv;

	av = (int *) a;
	bv = (int *) b;
	if (*av < *bv)
		return (0);
	return (-1);
}

size_t	ft_verifylist_byf(t_list *list, int (*f)(void *, void *))
{
	size_t	position;

	if (list == NULL)
		return (0);
	position = 1;
	while (list != NULL)
	{
		if ((*f)(list->content, list->next->content) == -1)
			return (position);
		list = list->next;
		position++;
	}
	return (0);
}

size_t	ft_list_iscircule(t_list *list, size_t n_dif)
{
	while (n_dif > 1)
	{
		list = list->next;
		n_dif--;
	}
	n_dif = ft_verifylist_byf(list, ft_inta_is_small);
	if (n_dif != 0)
		return (n_dif);
	else
		return (0)
}

size_t	ft_list_issorted(t_list *list)
{
	size_t	n_dif;

	n_dif = ft_verifylist_byf(list, ft_inta_is_small);
	return (n_dif);
}