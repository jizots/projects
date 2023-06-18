/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_over_six.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:55:59 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/18 19:56:03 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_simple_swap(sta, stb, -1);
		if (list_int[0] <= *((*sta)->cont) && *((*sta)->cont) <= list_int[((size_t)(size_stack / 23) + 9) + i])
		{
			ft_push(sta, stb, "pb");
			if ((*sta)->cont == NULL || (size_stack - i) == 1)
				break ;
			if (list_int[(size_t)(size_stack / 40) + 1 + i] <= *((*stb)->cont))
				*stb = ft_rotate(*stb, "rb");
			if (i < (size_stack - (size_t)(size_stack / 23) + 9 + 1))
				i++;
		}
		else
			*sta = ft_rotate(*sta, "ra");
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
		if ((*stb)->cont == NULL)
			break ;
		*stb = ft_rotate_repeat(*stb, "rb", "rrb", ft_locate_maximum(*stb));
		ft_push(stb, sta, "pa");
		ft_simple_swap(sta, stb, 0);
		size_stack -= 2;
	}
}

t_list	*ft_size_over_six(t_list *sta, t_list *stb, size_t size_stack)
{
	int	*list_int;

	if (ft_ascending_sorted(sta) == 0 && stb->cont == NULL)
		return (sta);
	list_int = ft_sort_int(sta);
	if (list_int == NULL)
	{
		ft_put_error(sta);
		return (NULL);
	}
	ft_push_tob_all(&sta, &stb, list_int, size_stack);
	ft_push_toa_all(&sta, &stb, list_int, size_stack);
	return (sta);
}
