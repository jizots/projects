/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:15:50 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/04 19:43:54 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lstadd_back(t_fdf **lst, t_fdf *new)
{
	t_fdf	*current;

	if (*lst == NULL && new != NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

// or
// void	ft_lstadd_back(t_fdf **lst, t_fdf *new)
// {
// 	while ((*lst)->next != NULL)
// 	{
// 		lst = (*lst)->next;
// 	}
// 	(*lst)->next = new;
// }
