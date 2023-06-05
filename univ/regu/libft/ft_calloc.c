/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:02:25 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:21:12 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*heapadd;
	size_t		i;

	if (size != 0 && LONG_MAX / size < nmemb)
		return (NULL);
	heapadd = malloc (size * nmemb);
	if (heapadd == NULL)
		return (heapadd);
	i = 0;
	while (i < size * nmemb)
		heapadd[i++] = 0;
	return ((void *) heapadd);
}
