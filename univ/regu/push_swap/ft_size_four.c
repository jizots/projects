#include "push_swap.h"

t_list	*ft_size_four_a(t_list *ra, t_list *rb)
{
	size_t	locate_min;

	locate_min = ft_locate_minimum(ra);
	if (ft_ascending_sorted(ra) == 0)
		return (ra);//end only rotate pattern??
	if (locate_min == 4)
		ra = ft_r_rotate(ra, "rra");
	else
	{
		while (locate_min--)
			ra = ft_rotate(ra, "ra");
	}
	ft_push(&ra, &rb, "pb");
	ra = ft_size_three_a(ra);
	ft_push(&rb, &ra, "pa");
	return (ra);
}