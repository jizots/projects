/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:06:46 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/18 19:56:30 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_b.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while ((i < (size - 1)) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

int	ft_lstsize(t_list *list)
{
	int	value_return;

	if (list == NULL)
		return (0);
	value_return = 0;
	while (list->cont != NULL)
	{
		list = list->next;
		value_return++;
		if (value_return < 0)
			return (-1);
	}
	return (value_return);
}
