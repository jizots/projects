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

#include "push_swap_b.h"

t_list	*b_rotate(t_list *list)
{
	t_list	*newroot;
	t_list	*sentinel;

	if (list->next->cont == NULL || list->cont == NULL)
		return (list);
	newroot = list->next;
	sentinel = list->prev;
	sentinel->prev->next = list;
	list->prev = sentinel->prev;
	list->next = sentinel;
	sentinel->prev = list;
	sentinel->next = newroot;
	newroot->prev = sentinel;
	return (sentinel->next);
}

t_list	*b_r_rotate(t_list *list)
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
	return (newroot);
}

void	b_rotate_double(t_list **sta, t_list **stb)
{
	*sta = b_rotate(*sta);
	*stb = b_rotate(*stb);
}

void	b_r_rotate_double(t_list **sta, t_list **stb)
{
	*sta = b_r_rotate(*sta);
	*stb = b_r_rotate(*stb);
}
