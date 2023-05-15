#include "ft_printf.h"

//capture double bits to struct
t_sdouble	*capture_double_bits(uint64_t x, t_sdouble *sdouble)
{
	int	i;
	int	j;
	int	bits;

	i = 0;
	j = 0;
	bits = uint64_bits();
// printf("bits = %d\n",bits);
	while (i < 1)
	{
		if ((x >> (bits - i - 1)) & 1ULL)
			sdouble->sign = '1';
		else
			sdouble->sign = '0';
		i++;
	}
	j = 0;
	while (i < 12)
	{
		if ((x >> (bits - i - 1)) & 1ULL)
			sdouble->exponent[j++] = '1';
		else
			sdouble->exponent[j++] = '0';
		i++;
	}
	j = 0;
	while (i < bits)
	{
		if ((x >> (bits - i - 1)) & 1ULL)
			sdouble->fraction[j++] = '1';
		else
			sdouble->fraction[j++] = '0';
		i++;
	}
	return (sdouble);
}

t_sdouble	*initialize_sdouble(t_sdouble *sdouble)
{
	fill_null(sdouble->rev_integer, sizeof(sdouble->rev_integer));
	fill_null(sdouble->nor_decimals, sizeof(sdouble->nor_decimals));
	fill_null(sdouble->integer_bin, sizeof(sdouble->integer_bin));
	fill_null(sdouble->decimals_bin, sizeof(sdouble->decimals_bin));
	return (sdouble);
}

t_sdouble	*input_double_binary(t_sdouble *sdouble)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (sdouble->exp_int == 0)
	{
		sdouble->integer_bin[0] = '1';
		while (i < 52)
		{
			sdouble->decimals_bin[i] = sdouble->fraction[i];
			i++;
		}
	}
	else if (sdouble->exp_int < 0)
	{
		sdouble->integer_bin[0] = '\0';//will not need. only clarify.
		while ((i + 1) < -sdouble->exp_int)
		{
			sdouble->decimals_bin[i] = '0';
			i++;
		}
		sdouble->decimals_bin[i++] = '1';
		while (j < 23)
		{
			sdouble->decimals_bin[i++] = sdouble->fraction[j++];
		}
	}
	else if (sdouble->exp_int >= 52)
	{
		sdouble->integer_bin[i++] = '1';
		while (i <= 52)
		{
			sdouble->integer_bin[i] = sdouble->fraction[i - 1];
			i++;
		}
		while (i <= sdouble->exp_int)
		{
			sdouble->integer_bin[i++] = '0';
		}
		sdouble->decimals_bin[0] = '\0';//will not need. only clarify.
	}
	else
	{
		sdouble->integer_bin[i++] = '1';
		while (j < sdouble->exp_int)
		{
			sdouble->integer_bin[i++] = sdouble->fraction[j++];
		}
		i = 0;
		while (j < 52)
		{
			sdouble->decimals_bin[i++] = sdouble->fraction[j++];
		}
	}
	return (sdouble);
}

t_sdouble	*binary_to_intvalue_double(t_sdouble *sdouble) //oh.. func name is not appire func. separate func to integer and dicimal?
{
	size_t	i;
	size_t	len_intpart;
	size_t	len_decipart;
	char	temp_int[SIZEDOUBLE_INT];
	char	temp_deci[SIZEDOUBLE_DECI];

	i = 0;
	len_intpart = ft_strlen(sdouble->integer_bin);
	if (len_intpart == 0)
		sdouble->rev_integer[0] = '0';
	else if (len_intpart > 0)
	{
		while (i < len_intpart)
		{
			if (sdouble->integer_bin[i] == '1')
				add_num_of_revary(power_2_revary(temp_int, len_intpart - i - 1), sdouble->rev_integer);
			i++;
		}
	}
	i = 0;
	len_decipart = ft_strlen(sdouble->decimals_bin);
	if (binary_to_size(sdouble->decimals_bin, len_decipart) == 0)
		sdouble->nor_decimals[0] = '0';
	else if (len_decipart > 0)
	{
		while (i < len_decipart)
		{
			if (sdouble->decimals_bin[i] == '1')
				add_ary_of_frac(power_point5_ary(temp_deci, i + 1), sdouble->nor_decimals);
			i++;
		}
	}
	return (sdouble);
}

void	ft_putdouble(double d_num)
{
	t_udouble	u_dnum;
	t_sdouble	sdouble;

	initialize_sdouble(&sdouble);
	//enter float value you want culc.
	u_dnum.value = d_num;

// //copy bit expression to char array.
	capture_double_bits(u_dnum.bit_double, &sdouble);
// //and print array.its for your reference.
// int i = 0;
// int j;
// for (; i < 1; i++)
// 	printf("%c", sdouble.sign);
// for (j = 0; i < 12; i++)
// 	printf("%c", sdouble.exponent[j++]);
// for (j = 0; i < 52; i++)
// 	printf("%c", sdouble.fraction[j++]);
// puts("");

	//main
	sdouble.exp_int = (int)(binary_to_size(sdouble.exponent, sizeof(sdouble.exponent)) - 1023);
// printf("exp - 1023 :%d\n",sdouble.exp_int);
	input_double_binary(&sdouble);
// printf("integer_bin ;%s\n", sdouble.integer_bin);
// printf("decimals_bin ;%s\n", sdouble.decimals_bin);
	binary_to_intvalue_double(&sdouble);
	if (sdouble.sign == '1')
		write(1, "-", 1);
	ft_putstr_rev(sdouble.rev_integer);
	write (1, ".", 1);
	ft_putstr(sdouble.nor_decimals);
}
