#include "push_swap.h"

t_list	*ft_swap_single(t_list *list, char *action)
{
	t_list	*third_node;
	t_list	*sentinel;

	if (list == NULL)
		return (NULL);
	sentinel = list->prev;
	third_node = list->next->next;
	sentinel->next = list->next;
	if (ft_lstsize(list) == 2)
		sentinel->prev = list;
	sentinel->next->prev = sentinel;
	sentinel->next->next = list;
	list->prev = list->next;
	list->next = third_node;
	third_node->prev = list;
	if (action != NULL)
	{
		write(1, action, 2);
		write(1, "\n", 1);
	}
	return (sentinel->next);
}

void	ft_swap_double(t_list **lista, t_list **listb)
{
	*lista = ft_swap_single(*lista, NULL);
	*listb = ft_swap_single(*listb, NULL);
	write(1, "ss\n", 3);
}

void	ft_simple_swap(t_list **sta, t_list **stb, int flag)
{
	if ((*sta)->cont != NULL && (*stb)->cont != NULL &&
		ft_inta_is_small((*sta)->cont, (*sta)->next->cont) == -1 &&
			ft_intb_is_small((*stb)->cont, (*stb)->next->cont) == -1)
		ft_swap_double(sta, stb);
	else if (flag == 0 && (*sta)->cont != NULL && ft_inta_is_small((*sta)->cont, (*sta)->next->cont) == -1)
		*sta = ft_swap_single(*sta, "sa");
	else if ((*stb)->cont != NULL && ft_intb_is_small((*stb)->cont, (*stb)->next->cont) == -1)
		*stb = ft_swap_single(*stb, "sb");
}