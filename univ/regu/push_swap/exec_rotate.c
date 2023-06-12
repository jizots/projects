#include "push_swap.h"

void	ft_rotate(t_list *list, char *action)
{
	t_list	*tmp;
	t_list	*sentinel;

	tmp = list->prev->prev;
	sentinel = list->prev;
	tmp->next = list;
	sentinel->prev = list;
	sentinel->next = list->next;
	list->next->prev = sentinel;
	list->next = sentinel;
	list->prev = tmp;
	if (action != NULL)
	{
		write(1, action, 2);
		write(1, '\n', 1);
	}
}

void	ft_rotate_double(t_list *lista, t_list *listb)
{
	ft_rotate(lista, NULL);
	ft_rotate(listb, NULL);
	write(1, "rr\n", 3);
}