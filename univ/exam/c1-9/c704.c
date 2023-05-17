#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
//decimal to baseto
void    input_array(int decimal, char *result, int hexlen, size_t reslen)
{
    char c;
	if (decimal >= hexlen)
    {
        input_array(decimal / hexlen, result, hexlen, reslen - 1);
    }
    c = (decimal % hexlen) + '0';
    result[reslen - 1] = c;
}

char	*ft_input_baseto(int decimal, char *baseto, char *result)
{
    int	hexlen;
	size_t	reslen;
	int temp_decimal;

    hexlen = ft_strlen(baseto);
    reslen = 0;
	temp_decimal = decimal;
	while (temp_decimal != 0)
	{
		reslen++;
		temp_decimal = temp_decimal / hexlen;
	}
	result = malloc(sizeof(char) * (reslen + 2));
	if (result == NULL)
		printf("error");
	if (decimal < 0);
    else
	{
		result[reslen] = '\0';
		input_array(decimal, result, hexlen, reslen);
	}
	return (result);
}

char	*ft_atoi_base(char *str, char *base, char *baseto)
{
    int lenstr;
    int lenbase;
    int decimal;
	char *result;

    result = NULL;
	lenstr = ft_strlen(str);
    lenbase = ft_strlen(base);
	decimal = conv_decimal(str, base, lenstr, lenbase);
    result = ft_input_baseto(decimal, baseto, result);
	return (result);
}

int main()
{
    char     str[] = "1011";
    char    base[]="01";
    char    baseto[]="0123456789";

    printf("%s\n", ft_atoi_base(str, base, baseto));
    return (0);
}