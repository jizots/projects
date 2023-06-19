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

void	ft_push_tob_all_6to10(t_list **sta, t_list **stb)
{
	while ((*sta)->cont != NULL)
	{
		ft_simple_swap(sta, stb, -1);
		ft_push(sta, stb, "pb");
	}
}

void	ft_push_tob_all(t_list **sta, t_list **stb, int *lst_i, size_t size_lst)
{
	size_t	i;

	i = 0;
	while ((*sta)->cont != NULL)
	{
		ft_simple_swap(sta, stb, -1);
		if (lst_i[0] <= *((*sta)->cont)
			&& *((*sta)->cont) <= lst_i[((size_t)(size_lst * 0.04) + 10) + i])
		{
			ft_push(sta, stb, "pb");
			if ((*sta)->cont == NULL || (size_lst - i) == 1)
				break ;
			if (lst_i[(size_t)(size_lst * 0.025 + 0.5) + i] <= *((*stb)->cont))
				*stb = ft_rotate(*stb, "rb");
			if (i < (size_lst - ((size_t)(size_lst * 0.04) + 10 + 1)))
				i++;
		}
		else
			*sta = ft_rotate(*sta, "ra");
	}
}

size_t	ft_times_ratato(size_t locate_max, size_t locate_minus, size_t size_lst)
{
	size_t	times_rotate;

	if (locate_minus > (size_lst / 2) && locate_max > (size_lst / 2)
		&& locate_max > locate_minus)
		times_rotate = locate_max;
	else if (locate_minus > (size_lst / 2) && locate_max > (size_lst / 2))
		times_rotate = locate_minus;
	else if (locate_minus <= (size_lst / 2) && locate_max > (size_lst / 2)
		&& (size_lst - locate_max) < locate_minus)
		times_rotate = locate_max;
	else if (locate_minus <= (size_lst / 2) && locate_max > (size_lst / 2))
		times_rotate = locate_minus;
	else if (locate_minus > (size_lst / 2) && locate_max <= (size_lst / 2)
		&& locate_max < (size_lst - locate_minus))
		times_rotate = locate_max;
	else if (locate_minus > (size_lst / 2) && locate_max <= (size_lst / 2))
		times_rotate = locate_minus;
	else if (locate_max < locate_minus)
		times_rotate = locate_max;
	else
		times_rotate = locate_minus;
	return (times_rotate);
}

void	ft_push_toa_all(t_list **sta, t_list **stb, int *lst_i, size_t size_lst)
{
	size_t	locate_minus;
	size_t	locate_max;
	size_t	times_rotate;

	while ((*stb)->cont != NULL)
	{
		locate_max = ft_locate_specify(*stb, lst_i[size_lst - 1]);
		if (size_lst > 1)
			locate_minus = ft_locate_specify(*stb, lst_i[size_lst - 2]);
		times_rotate = ft_times_ratato(locate_max, locate_minus, size_lst);
		*stb = ft_rotate_repeat(*stb, "rb", "rrb", times_rotate);
		ft_push(stb, sta, "pa");
		if ((*stb)->cont == NULL)
			break ;
		*stb = ft_rotate_repeat(*stb, "rb", "rrb", ft_locate_maximum(*stb));
		ft_push(stb, sta, "pa");
		ft_simple_swap(sta, stb, 0);
		size_lst -= 2;
	}
}

t_list	*ft_size_over_six(t_list *sta, t_list *stb, size_t size_lst)
{
	int	*lst_i;

	if (ft_ascending_sorted(sta) == 0 && stb->cont == NULL)
		return (sta);
	lst_i = ft_sort_int(sta);
	if (lst_i == NULL)
	{
		ft_put_error(sta);
		return (NULL);
	}
	if (size_lst <= 10)
		ft_push_tob_all_6to10(&sta, &stb);
	else
		ft_push_tob_all(&sta, &stb, lst_i, size_lst);
	ft_push_toa_all(&sta, &stb, lst_i, size_lst);
	free(lst_i);
	return (sta);
}
