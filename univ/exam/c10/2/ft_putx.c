#include "ft102.h"

size_t ft_strlen(const char *str)
{
	size_t	count;
	
	count =0;
    while (str[count])
		count++;
    return (count);
}

char *ft_strncat(char *dest, const char *src, size_t n)
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
	if (i < n)
		dest[len_dest + i] = '\0';
	return (dest);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while(str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *src)
{
    int	i;
    int	result;

    i = 0;
    while (src[i] == ' ')
        i++;
	if (src[i] == '-')
    {
        i++;
    }
	else if (src[i] == '+')
    {
        i++;
    }
    result = 0;
    while (src[i])
    {
        if ('0' <= src[i] && src[i] <= '9')
			result = result * 10 + (src[i] - '0');
		else
			return (-1);
        i++;
    }
    return (result);
}