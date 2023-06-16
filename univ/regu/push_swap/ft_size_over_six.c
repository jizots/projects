#include "push_swap.h"

// static void	ft_sort_under_six(t_list **sta, t_list **stb)
// {
// 	size_t	size_sta;
// 	size_t	size_stb;

// // puts("under six");
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
// puts("simple");
	if ((*sta)->cont != NULL && (*stb)->cont != NULL && ft_inta_is_small((*sta)->cont, (*stb)->cont) == -1 && ft_intb_is_small((*sta)->cont, (*stb)->cont) == -1)
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

	i = 0;
	while (*(list->cont) != specify)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	ft_push_b_all(t_list *sta, t_list *stb, int median, int *list_int)
{
	size_t	small;
	size_t	big;

	while (sta->cont != NULL)
	{
		if (list_int[median + 1 + small] < *(sta->cont) < list_int[median + 2 + small])
		{
			ft_
		}
	}
}

t_list	*ft_size_over_six(t_list *sta, t_list *stb, size_t size_stack)
{
	int	*list_int;
	
	if (ft_ascending_sorted(sta) == 0 && stb->cont == NULL)
		return (sta);
	list_int = ft_sort_int(sta);
	ft_push_b_all(sta, stb, list_int[size_stack / 2], list_int);
	// ft_sort_under_six(&sta, &stb);
	// ft_simple_swap(&sta, &stb);
	// if (ave < *(sta->cont))
	// 	ft_push(&sta, &stb, "pa");
	// else
	// 	sta = ft_rotate(sta, "ra");
	// if (sta->cont == NULL)
	// 	flag = 1;
	// else if (stb->cont == NULL)
	// 	flag = 0;
	// if (sta->cont != NULL && flag == 0)
	// 	ft_push(&sta, &stb, "pb");
	// else if (stb->cont != NULL && flag == 1)
	// 	ft_push(&stb, &sta, "pa");
	return (ft_size_over_six(sta, stb, size_stack));
}