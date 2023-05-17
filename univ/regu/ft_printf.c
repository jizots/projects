#include "ft_printf.h"

//There are concern for initialization. Especially, wide and accuracy. Are there wrong usage risk, if reflect options?
void	initialize_t_format(t_format_print *s_fprint)
{
	ft_strncpy(s_fprint->flag, "", 8);
	s_fprint->wide_field = 0;
	s_fprint->accuracy = 0;
	s_fprint->length_modifiers = NULL;
	s_fprint->wait_flag = 0;
}

//Catch % sign and capture options to struct.
char	*if_capt_sign(const char *str, t_format_print *s_printf)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '%' && str[i + 1] != '%')
		{
			i++;
			while (str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == ' ' || str[i] == '+' || str[i] == 'l')
			{
				s_printf->flag[i] = str[i];
				i++;
			}
			while ('1' <= str[i] && str[i] <= '9') 
			{
				s_printf->wide_field = ft_atoi(&str[i]); //atoi じゃなく atosにした方がスムーズぽよ
				i = i + ft_num_of_digits_int(s_printf->wide_field); //size_t 作るぅ？
			}
			if (str[i] == '.')
			{
				i++;
				s_printf->accuracy = ft_atoi(&str[i]);
				i = i + ft_num_of_digits_int(s_printf->accuracy); //size_t 作るぅ？
			}
			if (str[i] >= 'a' && str[i] <= 'z')
				s_printf->conv_spec = str[i];
			s_printf->wait_flag = 1;
			i++;
			break ;
		}
		else
			ft_putchar(str[i++]);
	}
	if (str[i] == '\0')
		return (NULL);
	return ((char*)&str[i]);
}

int	ft_printf(const char *format, ...)
{
	int     		count;
	va_list			args;
	t_format_print	s_printf;
	int				num_int;
	char			c;
	char			*str;
	// float			f_num;
	double			d_num;
	void			*add;

	count = 0;
	initialize_t_format(&s_printf);
	va_start(args, format);
	while (format != NULL)
	{
		format = if_capt_sign(format, &s_printf);
		if (format == NULL && s_printf.wait_flag == 0)
			break ;
		if (s_printf.conv_spec == 'd')
		{
			num_int = va_arg(args, int);
			ft_putnbr_int(num_int);
		}
		else if (s_printf.conv_spec == 'c')
		{
			c = (char)va_arg(args, int);
			ft_putchar(c);
		}
		else if (s_printf.conv_spec == 's')
		{
			str = va_arg(args, char*);
			ft_putstr(str);
		}
		else if (s_printf.conv_spec == 'f')
		{
			// f_num = (float)va_arg(args, double);
			// ft_putfloat(f_num);
			d_num = va_arg(args, double);
			ft_putdouble(d_num);
		}
		else if (s_printf.conv_spec == 'p')
		{
			add = va_arg(args, void*);
			ft_print_address(add);
		}
		s_printf.wait_flag = 0;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	int		num=123;
	char	c='c';
	static char	str[]="string";
	float	dnum = 3412.013;
	// double	dnum = 12123.01234567;

	ft_printf("%s %d %c %s %f %pend\n", str, num, c, str, dnum, &dnum);
	printf("%s %d %c %s %.49f %pend\n", str, num, c, str, dnum, &dnum);
	ft_printf("%f %f\n", 9.0, 0.315);
	return 0;
}