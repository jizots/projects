#include "push_swap.h"

t_list	*ft_size_two_a(t_list *roota)
{
	if (ft_ascending_sorted(roota) != 0)
		roota = ft_swap_single(roota, "sa");
	return (roota);	
}

t_list	*ft_size_two_b(t_list *rootb)
{
	if (ft_descending_sorted(rootb) != 0)
		rootb = ft_swap_single(rootb, "sb");
	return (rootb);	
}