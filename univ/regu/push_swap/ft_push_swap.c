#include "push_swap.h"

t_list	*ft_push_swap(t_list *root)
{
	int		size_stack;

	size_stack = ft_lstsize(root);
	if (size_stack == 1)
		return (root);
	else if (size_stack == 2)
		return (ft_size_two(root));
	// else if (size_stack == 3)
	// 	return (ft_size_three(root));
	// else if (size_stack == 4)
	// 	return (ft_size_four(root));
	// else if (size_stack == 5)
	// 	return (ft_size_five(root));
	// else if (size_stack == 6)
	// 	return (ft_size_six(root));
	// else if (size_stack == 7)
	// 	return (ft_size_seven(root));
	// else
	// 	return (ft_size_more(root));
return (root);
}