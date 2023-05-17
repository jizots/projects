#include "ft_printf.h"

///  

//Verified.
int	ft_atoi(const char *src)
{
    int	i;
    int	result;
    int	sign_flag;

    i = 0;
    while (src[i] == ' ')
        i++;
	if (src[i] == '-')
    {
	    sign_flag = -1;
        i++;
    }
	else if (src[i] == '+')
        i++;
    result = 0;
    while (src[i])
    {
        if ('0' <= src[i] && src[i] <= '9')
			result = result * 10 + (src[i] - '0');
		else
			break ;
        i++;
    }
	if (sign_flag == -1)
	    return (-result);
	return (result);
}

//ft_atoi_base. Convert str(Based *base) to int.
int	base_check(char *base)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (base[i] == '\0')
		return (-1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
			return (-1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	str_check(char *str, char *base)
{
	size_t	i;
	size_t	len_str;
	int		j;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	len_str = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				break ;
			j++;
		}
		if (!base[j])
			break ;
		i++;
		len_str++;
	}
	return (len_str);
}

int	convert_int(char *str, char *base, size_t len_base, size_t len_str)
{
	int		i;
	size_t	num_base;
	size_t	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		num_base = 0;
		while (base[num_base])
		{
			if (base[num_base] == str[i])
				break ;
			num_base++;
		}
		result = result + (num_base * power_num(len_base, (len_str - 1 - i)));
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	size_t	i;
	size_t	len_str;
	size_t	len_base;
	int		minus;

	if (base_check(base) < 0)
		return (0);
	len_str =  str_check(str, base);
	if (len_str == 0)
		return (0);
	len_base = ft_strlen(base);
	i = 0;
	while (str[i] == ' ')
		i++;
	minus = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	str = &str[i];
	if (minus % 2)
		return (-convert_int(str, base, len_base, len_str));
	return (convert_int(str, base, len_base, len_str));
}

//