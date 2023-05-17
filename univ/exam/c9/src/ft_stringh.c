#include <stdio.h> 

void ft_swap_int(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x=*y;
	*y=temp;
}

size_t ft_strlen(const char *str){
    int	count;
	
	count =0;
    while (str[count])
		count++;
    return (count);
}

int	ft_numlen_int(int num)
{
	int	count;

	count = 0;
	if (num == -2147483648)
		return (11);
	else if (num < 0)
	{
		count++;
		num = -num;
	}
	if (num == 0)
		count++;
	while (num)
	{
		count++;
		num = num / 10;
	}
	return (count);
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

char *ft_strcat(char *dest, const char *src)
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

void	*memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_char;
	char	*src_char;
	size_t		i;

	dest_char = (char*)dest;
	src_char = (char*)src;
	i = 0;
	while (src_char[i] && i < n--)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return ((void*)dest_char);
}
