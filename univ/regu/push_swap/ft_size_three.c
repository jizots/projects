#include "push_swap.h"

t_list	*ft_size_three_a(t_list *ra)
{
	int vl[3];

	vl[0] = *(ra->cont);
	vl[1] = *(ra->next->cont);
	vl[2] = *(ra->next->next->cont);
	if (ft_ascending_sorted(ra) == 0)
		return (ra);
	if ((vl[0] < vl[1] && vl[0] < vl[2] && vl[1] > vl[2])
		|| (vl[0] > vl[1] && vl[0] < vl[2] && vl[1] < vl[2])
			|| (ft_descending_sorted(ra) == 0))
		ra = ft_swap_single(ra, "sa");
	if (vl[0] < vl[1] && vl[0] > vl[2] && vl[1] > vl[2])
		ra = ft_r_rotate(ra, "rra");
	else if (vl[0] > vl[1] && vl[0] > vl[2] && vl[1] < vl[2])
		ra = ft_rotate(ra, "ra");
	return (ft_size_three_a(ra));
}

t_list	*ft_size_three_b(t_list *rb)
{
	int vl[3];

	vl[0] = *(rb->cont);
	vl[1] = *(rb->next->cont);
	vl[2] = *(rb->next->next->cont);
	if (ft_descending_sorted(rb) == 0)
		return (rb);
	if ((vl[0] < vl[1] && vl[0] < vl[2] && vl[1] < vl[2])
		|| (vl[0] > vl[1] && vl[0] > vl[2] && vl[1] < vl[2])
			|| (ft_ascending_sorted(rb) == 0))
		rb = ft_swap_single(rb, "sb");
	if (vl[0] > vl[1] && vl[0] < vl[2] && vl[1] < vl[2])
		rb = ft_r_rotate(rb, "rrb");
	else if (vl[0] < vl[1] && vl[0] < vl[2] && vl[1] > vl[2])
		rb = ft_rotate(rb, "rb");
	return (ft_size_three_b(rb));
}