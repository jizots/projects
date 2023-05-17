#include "ft_printf.h"
#include <stdio.h> 


//Verified.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;
	size_t			i;

	dest_char = (unsigned char*)dest;
	src_char = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;
	size_t			i;

	dest_char = (unsigned char*)dest;
	src_char = (unsigned char*)src;
	i = 0;
	if ((dest_char - src_char) <= 0)
		while (i < n)
		{
			dest_char[i] = src_char[i];
			i++;
		}
	else
		while (i < n)
		{
			dest_char[n - 1 - i] = src_char[n - 1 - i];
			i++;
		}
	return (dest);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len_dest;
	size_t	i;

	len_dest = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (dest);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	if (n == 0)
		return (0);
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	i = 0;
	while (c1[i] == c2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (c1[i] - c2[i]);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] != '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i < n)
	{
		if (s1[i] != '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;
	size_t			i;

	if (n == 0)
		return (NULL);
	str = (unsigned char*)s;
	c1 = (unsigned char)c;
	i = 0;
	while (str[i] != c1 && i < n)
		i++;
	if (i == n)
		return (NULL);
	else
		return ((void*)&str[i]);
}

//Un-verified.
void ft_swap_int(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x=*y;
	*y=temp;
}

size_t ft_strlen(const char *str)
{
    size_t	count;
	
	count = 0;
    while (str[count])
		count++;
    return (count);
}

unsigned short	ft_num_of_digits_int(int num)
{
	int	count_digits;

	count_digits = 0;
	if (num == -2147483648)
		return (11);
	else if (num < 0)
	{
		count_digits++;
		num = -num;
	}
	if (num == 0)
		count_digits++;
	while (num)
	{
		count_digits++;
		num = num / 10;
	}
	return (count_digits);
}


const char	*ft_strstr(const char *haystack, const char *needle)
{
	int	start;
	int	i;

	start = 0;
	while (haystack[start] != '\0')
	{
		i = 0;
		while (needle[i] == haystack[start + i])
			i++;
		if (needle[i] == '\0')
			return (const char*)(&haystack[start]);
		else if (haystack[start + i] == '\0')
			return (const char*)(haystack);
		start++;
	}
	return (const char*)(haystack);
}
