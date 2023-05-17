#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *src)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (src[i++])
        count++;
    return (count);
}

int	power_lenbase(int lenbase, int power)
{
	int	result;

	result = 1;
	if (!power)
		return (1);
	while (power--)
	{
		result = lenbase * result;
	}
	return (result);
}

int	search_basenum(char c, char *base, int lenbase)
{
	int	i;

	i = 0;
	while (base[i] != c)
	{	
		if (i == lenbase)
			return (-1);
		i++;
	}
	return (i);
}

int	conv_decimal(char *str, char *base, int lenstr, int lenbase)
{
	int	power;
	int result;

	power = 0;
	result = 0;
	while(power < lenstr)
	{
		result += power_lenbase(lenbase, power) * search_basenum(str[lenstr - 1 - power], base, lenbase);
		power++;
	}
	return (result);
}

int ft_atoi_base(char *str, char *base)
{
    int lenstr;
    int lenbase;

    lenstr = ft_strlen(str);
    lenbase = ft_strlen(base);
	return (conv_decimal(str, base, lenstr, lenbase));
}

int main()
{
    char     str[] = "644e";
    char    base[]="0123456789abcdef";

    printf("%d\n", ft_atoi_base(str, base));
    return (0);
}