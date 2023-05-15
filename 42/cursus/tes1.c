#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*power_point5_ary(char *result, size_t power)
{
	int	i;
	int	flag;
	int	temp;

	if (power == 0)
		return (result);
	result[0] = '5';
	result[1] = '\0';
	if (power == 1)
		return (result);
	power--;
	while (power--)
	{
		i = 0;
		flag = 0;
		while (result[i])
		{
			temp = (result[i] - '0');
			if (flag == 1)
			{
				temp += 10;
				flag = 0;
			}
			result[i] = (temp / 2) + '0';
			if ((temp % 2) == 1)
				flag = 1;
			i++;
		}
		result[i] = '5';
		result[i + 1] = '\0';
	}
	return (result);
}


int main()
{
	char	num1[150] = "0009765625";
	char	num2[150] = "00392625";
	char	result[150];
	t_ufloat	a;

	a.value = 0.05;
	printf("%f\n",a.value);
	printf("%d\n",a.bit_float);

	return 0;
}