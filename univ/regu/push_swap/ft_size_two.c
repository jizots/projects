#include "push_swap.h"

t_list	*ft_size_two(t_list *root)
{
	if (ft_ascending_sorted(root) != 0)
		root = ft_swap_single(root, "sa");
	return (root);	
}