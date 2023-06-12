#include "push_swap.h"

int	ft_inta_is_small(void *a, void *b)
{
	int	*n1;
	int	*n2;

	n1 = (int *) a;
	n2 = (int *) b;
	if (*n1 < *n2)
		return (0);
	return (-1);
}

int	ft_intb_is_small(void *a, void *b)
{
	int	*n1;
	int	*n2;

	n1 = (int *) a;
	n2 = (int *) b;
	if (*n2 < *n1)
		return (0);
	return (-1);
}

static size_t	ft_verifylist_byf(t_list *list, int (*f)(void *, void *))
{
	size_t	position;

	if (list == NULL)
		return (0);
	position = 1;
	while (list->next->content != NULL)
	{
		if ((*f)(list->content, list->next->content) == -1)
			return (position);
		list = list->next;
		position++;
	}
	return (0);
}

size_t	ft_ascending_sorted(t_list *list)
{
	size_t	n_dif;

	n_dif = ft_verifylist_byf(list, ft_inta_is_small);
	return (n_dif);
}

size_t	ft_descending_sorted(t_list *list)
{
	size_t	n_dif;

	n_dif = ft_verifylist_byf(list, ft_intb_is_small);
	return (n_dif);
}