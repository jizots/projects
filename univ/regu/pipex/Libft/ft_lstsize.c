/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:17:37 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/24 13:17:39 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	value_return;

	if (lst == NULL)
		return (0);
	value_return = ft_lstsize(lst->next) + 1;
	if (value_return < 0)
		return (-2);
	return (value_return);
}
