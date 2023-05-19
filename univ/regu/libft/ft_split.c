#include <stdio.h>

size_t	num_of_split(const char *s, char c, size_t *len_strmax)
{
	int		i;
	size_t	num_split;
	size_t	len_temp;

	num_split = 0;
	*len_strmax = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			num_split++;
			while(s[i] != c && s[i] != '\0')
			{
				i++;
				len_temp++;
			}
			if (*len_strmax < len_temp)
				*len_strmax = len_temp;
		}
		else
		{
			while(s[i] == c && s[i] != '\0')
			{
				i++;
			}
		}
	}
}

char	**ft_split(const char *s, char c)
{
	char	**box;
	size_t	num_split;
	size_t	len_strmax;

	num_split = num_of_split(s, c, &len_strmax);
}