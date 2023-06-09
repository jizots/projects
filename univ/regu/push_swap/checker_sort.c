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

int	ft_listcont_tof(t_list *list, int (*f)(void *, void *))
{
	t_list	*next;
	size_t	position;

	if (list == NULL)
		return (0);
	position = 0;
	while (next != NULL)
	{
		if ((*f)(list->content, list->next->content) == -1)
			return (-1);
		next = list->next;
		position++;
	}
	return (position);
}

int	ft_iscircule(t_list *list)
{
	int		*n_root;
	t_list	*next;

	if (list == NULL)
		return (-1);
	n_root = (int *) list->content;
	next = list->next;
	while (list != NULL)
	{
		next = list->next;
		if (next != NULL && ft_listcont_tof(list, ft_inta_is_small) != -1)

	}
}