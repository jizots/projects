#include "push_swap.h"

static t_list	*ft_create_bstack(void *cont)
{
	t_list	*new;

	new = malloc (sizeof(t_list) * 1);
	if (new == NULL)
		return (NULL);
	new->cont = cont;
	new->prev = new;
	new->next = new;
	return (new);
}

t_list	*ft_push_swap(t_list *roota)
{
	int		size_stack;
	t_list	*rootb;

	rootb = ft_create_bstack(NULL);
	size_stack = ft_lstsize(roota);
	if (size_stack == 1)
		return (roota);
	else if (size_stack == 2)
		return (ft_size_two_a(roota));
	else if (size_stack == 3)
		return (ft_size_three_a(roota));
	else if (size_stack == 4)
		return (ft_size_four_a(roota, rootb));
	// else if (size_stack == 5)
	// 	return (ft_size_five(roota));
	// else if (size_stack == 6)
	// 	return (ft_size_six(roota));
	// else
	// 	return (ft_size_more(roota));
return (roota);
}