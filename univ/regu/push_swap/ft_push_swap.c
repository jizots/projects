/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:55:17 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/18 19:55:19 by sotanaka         ###   ########.fr       */
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

static t_list	*ft_create_bstack(void)
{
	t_list	*new;

	new = malloc (sizeof(t_list) * 1);
	if (new == NULL)
		return (NULL);
	new->cont = NULL;
	new->prev = new;
	new->next = new;
	return (new);
}

t_list	*ft_push_swap(t_list *sta)
{
	int		size_stack;
	t_list	*stb;

	stb = ft_create_bstack();
	if (stb == NULL)
	{
		ft_put_error(sta);
		return (NULL);
	}
	size_stack = ft_lstsize(sta);
	if (size_stack == 1)
		;
	else if (size_stack == 2)
		sta = ft_size_two_a(sta);
	else if (size_stack == 3)
		sta = ft_size_three_a(sta);
	else if (size_stack == 4)
		sta = ft_size_four_a(sta, stb);
	else if (size_stack == 5)
		sta = ft_size_five_a(sta, stb);
	else
		sta = ft_size_over_six(sta, stb, size_stack);
	ft_delete_datas(stb);
	return (sta);
}
