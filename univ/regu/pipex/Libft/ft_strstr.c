/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:08:18 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/24 15:27:56 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	start;
	size_t	i;

	start = 0;
	if (needle == NULL)
		return (NULL);
	if (*haystack == '\0' && *needle == '\0')
		return ((char *) haystack);
	while (haystack[start] != '\0')
	{
		i = 0;
		while (needle[i] == haystack[start + i] && needle[i] != '\0')
			i++;
		if (needle[i] == '\0')
			return ((char *) &haystack[start]);
		if (haystack[start + i] == '\0')
			return (NULL);
		start++;
	}
	return (NULL);
}

// int main()
// {
// 	char *s1 = "MZIRIBMZIRIBMZP";
// 	char *s2 = "MZIRIBMZP";
// 	char *i1 = strstr(s1, s2);
// 	char *i2 = ft_strstr(s1, s2);

// 	printf("%s\n", i1);
// 	printf("%s", i2);
// }
