/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:09:02 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:09:06 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
		len = 0;
	errno = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, &s[start], len + 1);
	return (dest);
}

// int main()
// {
//     char    str1[]="qwertyuiopasdfghjkl";
// 	char *s = "libft-test-tokyo";
//    	printf("%s\n",ft_substr("", -1, -1));
//    	printf("%s\n",ft_substr(str1, 1, 3));
//    	printf("%s\n",ft_substr(s, 0, 100));
//    	printf("%s\n",ft_substr(s, 10, 100));
//    	printf("%s\n",ft_substr(s, 20, 0));
// 	// char *s = "libft-test-tokyo";
// 	// /* 1 */ ASSERT_EQ_STR(, s);
// 	// /* 3 */ ASSERT_EQ_STR(ft_substr(s, 5, 100), s + 5);
// 	// /* 3 */ ASSERT_EQ_STR(ft_substr(s, 10, 100), s + 10);
// 	// /* 4 */ ASSERT_EQ_STR(ft_substr(s, 15, 100), s + 15);
// 	// /* 5 */ ASSERT_EQ_STR(ft_substr(s, 20, 100), "");
// 	// /* 6 */ ASSERT_EQ_STR(ft_substr(s, 0, 5), "libft");
// 	// /* 7 */ ASSERT_EQ_STR(ft_substr(s, 5, 5), "-test");
// 	// /* 8 */ ASSERT_EQ_STR(ft_substr(s, 10, 5), "-toky");
// 	// /* 9 */ ASSERT_EQ_STR(ft_substr(s, 15, 5), "o");
// 	// /* 10 */ ASSERT_EQ_STR(ft_substr(s, 20, 5), "");
// 	// /* 11 */ ASSERT_EQ_STR(ft_substr(s, 0, 0), "");
// 	// /* 12 */ ASSERT_EQ_STR(ft_substr(s, 5, 0), "");
// 	// /* 13 */ ASSERT_EQ_STR(ft_substr(s, 10, 0), "");
// 	// /* 14 */ ASSERT_EQ_STR(ft_substr(s, 15, 0), "");
// 	// /* 15 */ ASSERT_EQ_STR(ft_substr(s, 20, 0), "");
// }
