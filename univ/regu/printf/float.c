#include "ft_printf.h"

//capture float bits to struct
t_sfloat	*capture_float_bits(unsigned x, t_sfloat *s_fnum)
{
	int	i;
	int	j;
	int	bits;

	i = 0;
	j = 0;
	bits = int_bits();
	while (i < 1)
	{
		if ((x >> (bits - i - 1)) & 1U)
			s_fnum->sign = '1';
		else
			s_fnum->sign = '0';
		i++;
	}
	j = 0;
	while (i < 9)
	{
		if ((x >> (bits - i - 1)) & 1U)
			s_fnum->exponent[j++] = '1';
		else
			s_fnum->exponent[j++] = '0';
		i++;
	}
	j = 0;
	while (i < bits)
	{
		if ((x >> (bits - i - 1)) & 1U)
			s_fnum->fraction[j++] = '1';
		else
			s_fnum->fraction[j++] = '0';
		i++;
	}
	return (s_fnum);
}

t_sfloat	*initialize_sfloat(t_sfloat *sfloat)
{
	fill_null(sfloat->rev_integer, sizeof(sfloat->rev_integer));
	fill_null(sfloat->nor_decimals, sizeof(sfloat->nor_decimals));
	fill_null(sfloat->integer_bin, sizeof(sfloat->integer_bin));
	fill_null(sfloat->decimals_bin, sizeof(sfloat->decimals_bin));
	return (sfloat);
}

t_sfloat	*input_float_binary(t_sfloat *sfloat)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (sfloat->exp_int == 0)
	{
		sfloat->integer_bin[0] = '1';
		while (i < 23)
		{
			sfloat->decimals_bin[i] = sfloat->fraction[i];
			i++;
		}
	}
	else if (sfloat->exp_int < 0)
	{
		sfloat->integer_bin[0] = '\0';//will not need. only clarify.
		while ((i + 1) < -sfloat->exp_int)
		{
			sfloat->decimals_bin[i] = '0';
			i++;
		}
		sfloat->decimals_bin[i++] = '1';
		while (j < 23)
		{
			sfloat->decimals_bin[i++] = sfloat->fraction[j++];
		}
	}
	else if (sfloat->exp_int >= 23)
	{
		sfloat->integer_bin[i++] = '1';
		while (i <= 23)
		{
			sfloat->integer_bin[i] = sfloat->fraction[i - 1];
			i++;
		}
		while (i <= sfloat->exp_int)
		{
			sfloat->integer_bin[i++] = '0';
		}
		sfloat->decimals_bin[0] = '\0';
	}
	else
	{
		sfloat->integer_bin[i++] = '1';
		while (j < sfloat->exp_int)
		{
			sfloat->integer_bin[i++] = sfloat->fraction[j++];
		}
		i = 0;
		while (j < 23)
		{
			sfloat->decimals_bin[i++] = sfloat->fraction[j++];
		}
	}
	return (sfloat);
}

t_sfloat	*binary_to_intvalue(t_sfloat *sfloat) //oh.. func name is not appire func
{
	size_t	i;
	size_t	len_intpart;
	size_t	len_decipart;
	char	temp_int[SIZEFLOAT_INT];
	char	temp_deci[SIZEFLOAT_DECI];

	i = 0;
	len_intpart = ft_strlen(sfloat->integer_bin);
	if (len_intpart == 0)
		sfloat->rev_integer[0] = '0';
	else if (len_intpart > 0)
	{
		while (i < len_intpart)
		{
			if (sfloat->integer_bin[i] == '1')
				add_num_of_revary(power_2_revary(temp_int, len_intpart - i - 1), sfloat->rev_integer);
			i++;
		}
	}
	i = 0;
	len_decipart = ft_strlen(sfloat->decimals_bin);
	if (binary_to_size(sfloat->decimals_bin, len_decipart) == 0)
		sfloat->nor_decimals[0] = '0';
	else if (len_decipart > 0)
	{
		while (i < len_decipart)
		{
			if (sfloat->decimals_bin[i] == '1')
				add_ary_of_frac(power_point5_ary(temp_deci, i + 1), sfloat->nor_decimals);
			i++;
		}
	}
	return (sfloat);
}

void	ft_putfloat(float f_num)
{
	t_ufloat	u_fnum;
	t_sfloat	s_fnum;

	initialize_sfloat(&s_fnum);
	//enter float value you want culc.
	u_fnum.value = f_num;

// //copy bit expression to char array.
	capture_float_bits(u_fnum.bit_float, &s_fnum);
// //and print array.its for your reference.
int i = 0;
int j;
for (; i < 1; i++)
	printf("%c", s_fnum.sign);
for (j = 0; i < 9; i++)
	printf("%c", s_fnum.exponent[j++]);
for (j = 0; i < 32; i++)
	printf("%c", s_fnum.fraction[j++]);
puts("");

	//main
	s_fnum.exp_int = (int)(binary_to_size(s_fnum.exponent, sizeof(s_fnum.exponent)) - 127);
printf("exp -127 :%d\n",s_fnum.exp_int);
	input_float_binary(&s_fnum);
printf("integer_bin ;%s\n", s_fnum.integer_bin);
printf("decimals_bin ;%s\n", s_fnum.decimals_bin);
	binary_to_intvalue(&s_fnum);
	if (s_fnum.sign == '1')
		write(1, "-", 1);
	ft_putstr_rev(s_fnum.rev_integer);
	write (1, ".", 1);
	ft_putstr(s_fnum.nor_decimals);
}
