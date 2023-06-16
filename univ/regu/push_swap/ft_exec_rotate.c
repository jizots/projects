#include "push_swap.h"

t_list	*ft_rotate(t_list *list, char *action)
{
	t_list	*newroot;
	t_list	*sentinel;

	newroot = list->next;
	sentinel = list->prev;
	sentinel->prev->next = list;
	list->prev = sentinel->prev;
	list->next = sentinel;
	sentinel->prev = list;
	sentinel->next = newroot;
	newroot->prev = sentinel;
	if (action != NULL)
	{
		write(1, action, 2);
		write(1, "\n", 1);
	}
// puts("->>>rotate<<<-");printf_list(sentinel->next);
	return (sentinel->next);
}

void	ft_rotate_double(t_list **lista, t_list **listb)
{
	*lista = ft_rotate(*lista, NULL);
	*listb = ft_rotate(*listb, NULL);
	write(1, "rr\n", 3);
// puts("->>>rotate double - a<<<-");printf_list(*lista);
// puts("->>>rotate double - b<<<-");printf_list(*listb);
}

t_list	*ft_r_rotate(t_list *list, char *action)
{
	t_list	*newroot;
	t_list	*sentinel;

	if (ft_lstsize(list) == 2)
		list->next = list->prev;
	newroot = list->prev->prev;
	sentinel = list->prev;
	sentinel->prev = newroot->prev;
	sentinel->prev->next = sentinel;
	sentinel->next = newroot;
	newroot->prev = sentinel;
	newroot->next = list;
	list->prev = newroot;
	if (action != NULL)
	{
		write(1, action, 3);
		write(1, "\n", 1);
	}
// puts("->>> r rotate<<<-");printf_list(newroot);
	return (newroot);
}

void	ft_r_rotate_double(t_list **lista, t_list **listb)
{
	*lista = ft_r_rotate(*lista, NULL);
	*listb = ft_r_rotate(*listb, NULL);
	write(1, "rr\n", 3);
// puts("->>> r rotate double - a<<<-");printf_list(*lista);
// puts("->>> r rotate double - b<<<-");printf_list(*listb);
}