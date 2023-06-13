#include "push_swap.h"

t_list	*ft_swap_single(t_list *list, char *action)
{
	t_list	*third_node;
	t_list	*sentinel;

	sentinel = list->prev;
	third_node = list->next->next;
	sentinel->next = list->next;
	if (ft_lstsize(list) == 2)
		sentinel->prev = list;
	sentinel->next->prev = sentinel;
	sentinel->next->next = list;
	list->prev = list->next;
	list->next = third_node;
	if (action != NULL)
	{
		write(1, action, 2);
		write(1, "\n", 1);
	}
	return (sentinel->next);
}

void	ft_swap_double(t_list *lista, t_list *listb)
{
	ft_swap_single(lista, NULL);
	ft_swap_single(listb, NULL);
	write(1, "ss\n", 3);
}