#include "push_swap.h"

// static void	ft_sort_under_six(t_list **sta, t_list **stb)
// {
// 	size_t	size_sta;
// 	size_t	size_stb;

// puts("under six");
// 	size_sta = ft_lstsize(*sta);
// 	size_stb = ft_lstsize(*stb);
// 	if (size_sta == 5)
// 		*sta = ft_size_five_a(*sta, *stb);
// 	else if (size_sta == 4)
// 		*sta = ft_size_four_a(*sta, *stb);
// 	else if (size_sta == 3)
// 		*sta = ft_size_three_a(*sta);
// 	else if (size_sta == 2)
// 		*sta = ft_size_two_a(*sta);
// 	if (size_stb == 5)
// 		*stb = ft_size_five_b(*sta, *stb);
// 	else if (size_stb == 4)
// 		*stb = ft_size_four_b(*sta, *stb);
// 	else if (size_stb == 3)
// 		*stb = ft_size_three_b(*stb);
// 	else if (size_stb == 2)
// 		*stb = ft_size_two_b(*stb);
// }

static void	ft_simple_swap(t_list **sta, t_list **stb)
{
	if ((*sta)->cont != NULL && (*stb)->cont != NULL &&
		ft_inta_is_small((*sta)->cont, (*sta)->next->cont) == -1 &&
			ft_intb_is_small((*stb)->cont, (*stb)->next->cont) == -1)
		ft_swap_double(sta, stb);
	else if ((*sta)->cont != NULL && ft_inta_is_small((*sta)->cont, (*sta)->next->cont) == -1)
		*sta = ft_swap_single(*sta, "sa");
	else if ((*stb)->cont != NULL && ft_intb_is_small((*stb)->cont, (*stb)->next->cont) == -1)
		*stb = ft_swap_single(*stb, "sb");
// puts("simple end");
}

size_t	ft_locate_specify(t_list *list, int specify)
{
	size_t	i;

	if (list->cont == NULL)
		return (0);
	i = 0;
	while (*(list->cont) != specify)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	ft_push_tob_all(t_list **sta, t_list **stb, int *list_int, size_t size_stack)
{
	size_t	i;

	i = 0;
	while ((*sta)->cont != NULL)
	{
		// ft_sort_under_six(sta, stb);
		ft_simple_swap(sta, stb);
// printf("cont %d\n", *((*sta)->cont));
// printf("listint %d<->%d\n", list_int[0], list_int[5+i]);
		if (list_int[0] <= *((*sta)->cont) && *((*sta)->cont) <= list_int[10 + i]) //100->10 , 500->27
		{
			ft_push(sta, stb, "pb");
			if (list_int[7 + i] <= *((*stb)->cont))
				*stb = ft_rotate(*stb, "rb");
			if (i < (size_stack - 11))//100->11 , 500->28
				i++;
		}
		else
			*sta = ft_rotate(*sta, "ra");
// puts("---> a <---");
// printf_list(*sta);
// puts("---> b <---");
// printf_list(*stb);
	}
}

size_t	ft_times_ratato(size_t locate_max, size_t locate_minus, size_t size_stack)
{
	size_t	times_rotate;

		if (locate_minus > (size_stack / 2) && locate_max > (size_stack / 2)
			&& locate_max > locate_minus)
			times_rotate = locate_max;
		else if (locate_minus > (size_stack / 2) && locate_max > (size_stack / 2))
			times_rotate = locate_minus;
		else if (locate_minus <= (size_stack / 2) && locate_max > (size_stack / 2)
			&& (size_stack - locate_max) < locate_minus)
			times_rotate = locate_max;
		else if (locate_minus <= (size_stack / 2) && locate_max > (size_stack / 2))
			times_rotate = locate_minus;
		else if (locate_minus > (size_stack / 2) && locate_max <= (size_stack / 2)
			&& locate_max < (size_stack - locate_minus))
			times_rotate = locate_max;
		else if (locate_minus > (size_stack / 2) && locate_max <= (size_stack / 2))
			times_rotate = locate_minus;
		else if (locate_max < locate_minus)
			times_rotate = locate_max;
		else
			times_rotate = locate_minus;
		return (times_rotate);
}

void	ft_push_toa_all(t_list **sta, t_list **stb, int *list_int, size_t size_stack)
{
	size_t	locate_minus;
	size_t	locate_max;
	size_t	times_rotate;

	while ((*stb)->cont != NULL)
	{
		locate_max = ft_locate_specify(*stb, list_int[size_stack - 1]);
		if (size_stack > 1)
			locate_minus = ft_locate_specify(*stb, list_int[size_stack - 2]);
		times_rotate = ft_times_ratato(locate_max, locate_minus, size_stack);
		*stb = ft_rotate_repeat(*stb, "rb", "rrb", times_rotate);
		ft_push(stb, sta, "pa");
		*stb = ft_rotate_repeat(*stb, "rb", "rrb", ft_locate_maximum(*stb));
		ft_push(stb, sta, "pa");
		ft_simple_swap(sta, stb);
		size_stack -= 2;
puts("---> a <---");
printf_list(*sta);
puts("---> b <---");
printf_list(*stb);
	}
}

t_list	*ft_size_over_six(t_list *sta, t_list *stb, size_t size_stack)
{
	int	*list_int;
	
	if (ft_ascending_sorted(sta) == 0 && stb->cont == NULL)
		return (sta);
	list_int = ft_sort_int(sta);
	ft_push_tob_all(&sta, &stb, list_int, size_stack);
	ft_push_toa_all(&sta, &stb, list_int, size_stack);
	return (sta);
}