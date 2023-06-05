#include "get_next_line.h"

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

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;
	size_t			i;

	str = (unsigned char *) s;
	c1 = (unsigned char) c;
	if (n == 0 || s == NULL)
		return (NULL);
	i = 0;
	while (i < n && str[i] != c1)
		i++;
	if (i == n)
		return (NULL);
	else
		return ((void *) &str[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;

	len_s = ft_strlen(src);
	if (dest == NULL)
		return (size + len_s);
	len_d = ft_strlen(dest);
	if (size <= len_d)
		return (size + len_s);
	while (*dest)
		dest++;
	while (size - len_d - 1)
	{
		*dest++ = *src++;
		size--;
		if (*src == '\0')
			break ;
	}
	*dest = '\0';
	return (len_d + len_s);
}