#include "push_swap.h"

t_list	*ft_size_five_a(t_list *sta, t_list *stb)
{
puts("size five");
	size_t	locate_min;

	if (ft_ascending_sorted(sta) == 0)
		return (sta);
	locate_min = ft_ascending_circle(sta);
	if (locate_min != 0)
		return (ft_rotate_repeat(sta, "ra", "rra", locate_min));
	locate_min = ft_locate_minimum(sta);
	sta = ft_rotate_repeat(sta, "ra", "rra", locate_min);
	ft_push(&sta, &stb, "pb");
	sta = ft_size_four_a(sta, stb);
	ft_push(&stb, &sta, "pa");
	return (sta);
}

t_list	*ft_size_five_b(t_list *sta, t_list *stb)
{
	size_t	locate_max;

	if (ft_descending_sorted(stb) == 0)
		return (stb);
	locate_max = ft_descending_circle(stb);
	if (locate_max != 0)
		return (ft_rotate_repeat(stb, "rb", "rrb", locate_max));
	locate_max = ft_locate_maximum(stb);
	stb = ft_rotate_repeat(stb, "rb", "rrb", locate_max);
	ft_push(&stb, &sta, "pa");
	stb = ft_size_four_b(sta, stb);
	ft_push(&sta, &stb, "pb");
	return (stb);
}