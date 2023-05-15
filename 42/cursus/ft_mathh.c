#include "ft_printf.h"

#include <errno.h>
#include <math.h>
#include <stdio.h>

int power_10(int power)
{
	int	result;

	result = 1;
    if (power == 0)
        return (1);
    while(power--)
        result = result * 10;
    return (result);
}

//return power of 2. Result is provided by reversed char array.
char	*power_2_revary(char *result, size_t power)
{
	int	i;
	int	flag;
	int	temp;

	result[0] = '1';
	result[1] = '\0';
	if (power == 0)
		return (result);
	while (power--)
	{
		i = 0;
		flag = 0;
		while (result[i])
		{
			temp = (result[i] - '0') * 2;
			result[i] = (temp % 10) + '0';
			if (flag == 1)
			{
				result[i] += 1;
				flag = 0;
			}
			if (temp > 9)
				flag = 1;
			i++;
		}
		if (temp > 9)
		{
			result[i] = (temp / 10) + '0';
			result[i + 1] = '\0';
		}
		else
			result[i] = '\0';
	}
	return (result);
}

//can use only not include minus
int	power_num(int num, int power)
{
	int	result;

	result = 1;
	if (power == 0 || num == 1)
		return (1);
	while (power--)
	{
		result = num * result;
	}
	return (result);
}

//permise: Power is sign reversed(turn to plus) int-type.
double	minus_power_binary(int power)
{
	double	result;

	if (power == 0)
		return (1);
	result = 1.0;
	while (power--)
	{
		result = (1.0 / 2.0) * result;
	}
	return (result);
}

//Return power of 1/2(zero point five). Result is only after zero point(not include 0.).
char	*power_point5_ary(char *result, size_t power)
{
	int	i;
	int	flag;
	int	temp;

	if (power == 0)
		return (NULL);
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

//making..
double ft_sqrt_double(double x)
{
	double	result;

	result = 0.0;
	if (x < 0)
	{
		errno = EDOM;
		return (NAN);
	}
	return (result);
}

//Convert binary array(that means integer) to decimal integer.
size_t	binary_to_size(char *binstr, size_t len_binstr)
{
	int		i;
	int		result;
	
	result = 0;
	i = 0;
	while (len_binstr--)
	{
		if (binstr[len_binstr] == '1')
			result = result + power_num(2, i);
		i++;
	}
	return(result);
}

char	*add_num_of_revary(char *num, char *result)
{
	int		flag_carry;
	int		temp;
	int		i;
	char	*remain_array;

	i = 0;
	flag_carry = 0;
	while (num[i] != '\0' && result[i] != '\0')
	{
		temp = (num[i] - '0') + (result[i] - '0');
		if (flag_carry == 1)
		{
			temp += 1;
			flag_carry = 0;
		}
		result[i] = (temp % 10) + '0';
		if (temp > 9)
			flag_carry = 1;
		i++;
	}
	if (num[i] != '\0')
		remain_array = num;
	else if (result[i] != '\0')
		remain_array = result;
	else if (flag_carry == 1)
	{
		result[i] = '1';
		return (result);
	}
	else
		return (result);
	result[i] = remain_array[i];
	if (flag_carry == 1)
		result[i] += 1;
	i++;
	while(remain_array[i] != '\0')
	{
		result[i] = remain_array[i];
		i++;
	}
	return (result);
}

char	*add_ary_of_frac(char *num, char *result)
{
	int		offset;
	int		len_long;
	char	*ad_temp;
	int		temp;
	int		flag;

	len_long = ft_strlen(num);
	if (len_long >= (int)ft_strlen(result))
	{
		offset = len_long - ft_strlen(result);
	}
	else
	{
		len_long = ft_strlen(result);
		offset = len_long - ft_strlen(num);
		ad_temp = num;
		num = result;
		result = ad_temp;
	}
	result[len_long--] = '\0';
	while (offset-- > 0)
	{
		result[len_long] = num[len_long];
		len_long--;
	}
	flag = 0;
	while (len_long >= 0)
	{
		temp = (num[len_long] - '0') + (result[len_long] - '0');
		if (flag == 1)
		{
			temp += 1;
			flag = 0;
		}
		result[len_long] = (temp % 10) + '0';
		if (temp > 9)
			flag = 1;
		len_long--;
	}
	return (result);
}

//Addition of two decimal integer (char-type based and reversed).
char	*add_num_of_revary_genesis(char *numarray1, char *numarray2, char *result)
{
	int		flag_carry;
	int		temp;
	int		i;
	char	*remain_array;

	i = 0;
	flag_carry = 0;
	while (numarray1[i] != '\0' && numarray2[i] != '\0')
	{
		temp = (numarray1[i] - '0') + (numarray2[i] - '0');
		if (flag_carry == 1)
		{
			temp += 1;
			flag_carry = 0;
		}
		result[i] = (temp % 10) + '0';
		if (temp > 9)
			flag_carry = 1;
		i++;
	}
	if (numarray1[i] != '\0')
		remain_array = numarray1;
	else if (numarray2[i] != '\0')
		remain_array = numarray2;
	else if (flag_carry == 1)
	{
		result[i] = '1';
		return (result);
	}
	else
		return (result);
	result[i] = remain_array[i];
	if (flag_carry == 1)
		result[i] += 1;
	i++;
	while(remain_array[i] != '\0')
	{
		result[i] = remain_array[i];
		i++;
	}
	return (result);
}

char	*add_ary_of_frac_genesis(char *num1, char *num2, char *result)
{
	int		offset;
	int		len_long;
	char	*ad_temp;
	int		temp;
	int		flag;

	len_long = ft_strlen(num1);
	if (len_long >= (int)ft_strlen(num2))
	{
		offset = len_long - ft_strlen(num2);
	}
	else
	{
		len_long = ft_strlen(num2);
		offset = len_long - ft_strlen(num1);
		ad_temp = num1;
		num1 = num2;
		num2 = ad_temp;
	}
	result[len_long--] = '\0';
	while (offset-- > 0)
	{
		result[len_long] = num1[len_long];
		len_long--;
	}
	flag = 0;
	while (len_long >= 0)
	{
		temp = (num1[len_long] - '0') + (num2[len_long] - '0');
		if (flag == 1)
		{
			temp += 1;
			flag = 0;
		}
		result[len_long] = (temp % 10) + '0';
		if (temp > 9)
			flag = 1;
		len_long--;
	}
	return (result);
}

