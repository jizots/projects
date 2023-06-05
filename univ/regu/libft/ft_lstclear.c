/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:16:19 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/24 15:29:08 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t_next;
	t_list	*t_delet;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	t_delet = *lst;
	while (t_delet != NULL)
	{
		t_next = t_delet->next;
		(*del)(t_delet->content);
		free(t_delet);
		t_delet = t_next;
	}
	*lst = NULL;
}
