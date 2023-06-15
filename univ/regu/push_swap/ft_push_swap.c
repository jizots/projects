#include "push_swap.h"

static t_list	*ft_create_bstack()
{
	t_list	*new;

	new = malloc (sizeof(t_list) * 1);
	if (new == NULL)
		return (NULL);
	new->cont = NULL;
	new->prev = new;
	new->next = new;
	return (new);
}

t_list	*ft_push_swap(t_list *sta)
{
	int		size_stack;
	t_list	*stb;

	stb = ft_create_bstack();
	size_stack = ft_lstsize(sta);
	if (size_stack == 1)
		return (sta);
	else if (size_stack == 2)
		return (ft_size_two_a(sta));
	else if (size_stack == 3)
		return (ft_size_three_a(sta));
	else if (size_stack == 4)
		sta = ft_size_four_a(sta, stb);
	else if (size_stack == 5)
		sta = ft_size_five_a(sta, stb);
	else
		return (ft_size_over_six(sta, stb, 0));
	free (stb);
	return (sta);
}