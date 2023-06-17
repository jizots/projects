#include "push_swap.h"

t_list	*ft_size_two_a(t_list *sta)
{
// puts("size two a");
	if (ft_ascending_sorted(sta) != 0)
		sta = ft_swap_single(sta, "sa");
	return (sta);	
}

t_list	*ft_size_two_b(t_list *stb)
{
// puts("size two b");
	if (ft_descending_sorted(stb) != 0)
		stb = ft_swap_single(stb, "sb");
	return (stb);	
}