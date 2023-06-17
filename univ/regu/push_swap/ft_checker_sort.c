#include "push_swap.h"

int	ft_inta_is_small(int *a, int *b)
{
	if (b == NULL || *a < *b)
		return (0);
	return (-1);
}

int	ft_intb_is_small(int *a, int *b)
{
if (b != NULL)
printf("a %d, b %d\n", *a, *b);
	if (b == NULL || *b < *a)
		return (0);
	return (-1);
}

static size_t	ft_verifylist_byf(t_list *list, int (*f)(int *, int *))
{
	size_t	position;

	if (list == NULL)
		return (0);
	position = 1;
	while (list->next->cont != NULL)
	{
		if ((*f)(list->cont, list->next->cont) == -1)
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