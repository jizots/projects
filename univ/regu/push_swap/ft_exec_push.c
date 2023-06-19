/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:54:26 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/18 19:54:28 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **from, t_list **to, char *action)
{
	t_list	*tmp_fprev;
	t_list	*tmp_fnext;

	if (*from == NULL || *to == NULL)
		return ;
	tmp_fprev = (*from)->prev;
	tmp_fnext = (*from)->next;
	(*to)->prev->next = *from;
	(*from)->prev = (*to)->prev;
	(*from)->next = *to;
	(*to)->prev = *from;
	tmp_fprev->next = tmp_fnext;
	tmp_fnext->prev = tmp_fprev;
	*to = *from;
	*from = tmp_fnext;
	write(1, action, 2);
	write(1, "\n", 1);
}
