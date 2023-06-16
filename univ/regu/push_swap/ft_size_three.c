#include "push_swap.h"

t_list	*ft_size_three_a(t_list *sta)
{
// puts("three a");
	int vl[3];

	vl[0] = *(sta->cont);
	vl[1] = *(sta->next->cont);
	vl[2] = *(sta->next->next->cont);
	if (ft_ascending_sorted(sta) == 0)
		return (sta);
	if ((vl[0] < vl[1] && vl[0] < vl[2] && vl[1] > vl[2])
		|| (vl[0] > vl[1] && vl[0] < vl[2] && vl[1] < vl[2])
			|| (ft_descending_sorted(sta) == 0))
		sta = ft_swap_single(sta, "sa");
	if (vl[0] < vl[1] && vl[0] > vl[2] && vl[1] > vl[2])
		sta = ft_r_rotate(sta, "rra");
	else if (vl[0] > vl[1] && vl[0] > vl[2] && vl[1] < vl[2])
		sta = ft_rotate(sta, "ra");
	return (ft_size_three_a(sta));
}

t_list	*ft_size_three_b(t_list *stb)
{
// puts("three b");
	int vl[3];

	vl[0] = *(stb->cont);
	vl[1] = *(stb->next->cont);
	vl[2] = *(stb->next->next->cont);
	if (ft_descending_sorted(stb) == 0)
		return (stb);
	if ((vl[0] < vl[1] && vl[0] > vl[2] && vl[1] > vl[2])
		|| (vl[0] > vl[1] && vl[0] > vl[2] && vl[1] < vl[2])
			|| (ft_ascending_sorted(stb) == 0))
		stb = ft_swap_single(stb, "sb");
	if (vl[0] > vl[1] && vl[0] < vl[2] && vl[1] < vl[2])
		stb = ft_r_rotate(stb, "rrb");
	else if (vl[0] < vl[1] && vl[0] < vl[2] && vl[1] > vl[2])
		stb = ft_rotate(stb, "rb");
	return (ft_size_three_b(stb));
}