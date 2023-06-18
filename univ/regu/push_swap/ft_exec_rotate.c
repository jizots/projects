/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:54:37 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/18 19:54:40 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_rotate(t_list *list, char *action)
{
	t_list	*newroot;
	t_list	*sentinel;

	if (list->next->cont == NULL)
		return (list);
	newroot = list->next;
	sentinel = list->prev;
	sentinel->prev->next = list;
	list->prev = sentinel->prev;
	list->next = sentinel;
	sentinel->prev = list;
	sentinel->next = newroot;
	newroot->prev = sentinel;
	if (action != NULL)
	{
		write(1, action, 2);
		write(1, "\n", 1);
	}
	return (sentinel->next);
}

t_list	*ft_r_rotate(t_list *list, char *action)
{
	t_list	*newroot;
	t_list	*sentinel;

	if (list->next->cont == NULL)
		return (list);
	if (ft_lstsize(list) == 2)
		list->next = list->prev;
	newroot = list->prev->prev;
	sentinel = list->prev;
	sentinel->prev = newroot->prev;
	sentinel->prev->next = sentinel;
	sentinel->next = newroot;
	newroot->prev = sentinel;
	newroot->next = list;
	list->prev = newroot;
	if (action != NULL)
	{
		write(1, action, 3);
		write(1, "\n", 1);
	}
	return (newroot);
}
