#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	i;
	size_t	j;
	int		flag_replace;
	char	*start;
	char	*end;

	if (*set == '\0' || *s1 == '\0')
		return ;
	len_s1 = ft_strlen(s1);
	i = 0;
	start = s1[i];
	while (i < len_s1)
	{
		j = 0;
		flag_replace = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[i])
			{
				flag_replace = 1;
				break ;
			}
			j++;
		}
		if (flag_replace == 1)
		{
			start = &s1[i + 1];
		}
		else if (flag_replace == 0 && i == 0)
			break;
		i++;
	}
	i = 0;
	end = s1[len_s1 - 1];
	while (i < len_s1)
	{
		j = 0;
		flag_replace = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s1[len_s1 - 1 - i])
			{
				flag_replace = 1;
				break ;
			}
			j++;
		}
		if (flag_replace == 1)
		{
			end = &s1[len_s1 - 2 - i];
		}
		else if (flag_replace == 0 && i == 0)
			break;
		i++;
	}	
	if (start == s1[0] && end == s1[len_s1 - 1])
	{
		return (ft_strdup(s1));
	}
	j = (size_t)(end - start)
	if ()
}