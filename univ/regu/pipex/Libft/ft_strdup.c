/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:05:56 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:31:26 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;

	errno = 0;
	dest = malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, s);
	return (dest);
}

// int main()
// {
//     char    str1[]="";

//    	printf("%s\n",ft_strdup(str1));
//    	printf("%s\n",strdup(str1));
// }
