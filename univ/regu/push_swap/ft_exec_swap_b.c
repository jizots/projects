/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_initial_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:55:07 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/18 19:55:09 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_b.h"

t_list	*b_swap_single(t_list *list)
{
	t_list	*third_node;
	t_list	*sentinel;

	if (list == NULL)
		return (NULL);
	sentinel = list->prev;
	third_node = list->next->next;
	sentinel->next = list->next;
	if (ft_lstsize(list) == 2)
		sentinel->prev = list;
	sentinel->next->prev = sentinel;
	sentinel->next->next = list;
	list->prev = list->next;
	list->next = third_node;
	third_node->prev = list;
	return (sentinel->next);
}

void	b_swap_double(t_list **lista, t_list **listb)
{
	*lista = b_swap_single(*lista);
	*listb = b_swap_single(*listb);
}
