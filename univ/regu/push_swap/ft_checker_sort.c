#include "push_swap.h"

int	ft_inta_is_small(int *a, int *b)
{
// puts("a is s");
	if (b == NULL || *a < *b)
		return (0);
// printf("%d %d\n", *a, *b);
	return (-1);
}

int	ft_intb_is_small(int *a, int *b)
{
// puts("b is s");
	if (b == NULL || *b < *a)
		return (0);
// printf("%d %d\n", *a, *b);
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
// printf("ndif %zu\n", n_dif);
	return (n_dif);
}

size_t	ft_descending_sorted(t_list *list)
{
	size_t	n_dif;

	n_dif = ft_verifylist_byf(list, ft_intb_is_small);
	return (n_dif);
}