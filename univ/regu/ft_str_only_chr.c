#include "printf.h"
 
//verify same charactor is not include in a string.
int	ft_str_only_chr(char *str)
{
	size_t	len_str;
	size_t	start;
	size_t	i;

	len_str = ft_strlen(str);
	start = 0;
	while (str[start] != '\0')
	{
		i = start + 1;
		while (str[i] != '\0')
		{
			if (str[start] == str[i])
				return (-1);
			i++;
		}
		start++;
	}
	return (0);
}

// int main()
// {
// 	printf ("%d", ft_str_only_chr("asdfghjklqwaertyuio"));
// }