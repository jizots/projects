#include "printf.h"

static const char	*ft_put_before_directiv(const char *str, t_directiv *direct, size_t *result)
{
	int	len_direct;

	len_direct = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			len_direct = ft_capt_directiv(str, direct);
			if (len_direct != 0)
			{
				direct->flag_wait = 1;
				break ;
			}
		}
		ft_putchar(*str);
		*result += 1;
		str++;
	}
	return ((const char *) &str[len_direct]);
}

size_t	print_directives(const char *format, va_list args, size_t *result, t_directiv *direct)
{
	while (*format != '\0')
	{
		format = ft_put_before_directiv(format, direct, result);
		if (*format =='\0' && direct->flag_wait == 0)
			break ;
// printf("widastr;%d preastr;%d\n", direct->flag_widastr, direct->flag_precastr);
		if (direct->flag_widastr == 1)
			direct->field_width = va_arg(args, int);
		if (direct->flag_precastr == 1)
			direct->preci = va_arg(args, int);		
		if (direct->conv_spec == 'c')
			*result += ft_putchar_directiv((char)va_arg(args, int), direct);
		else if (direct->conv_spec == 's')
			*result += ft_putstr_directiv(va_arg(args, char *), direct);
		else if (direct->conv_spec == 'p')
			*result += ft_putadrs_directiv(va_arg(args, void *), direct);
		else if (direct->conv_spec == 'd' || direct->conv_spec == 'i')
			*result += ft_putnbr_directiv(va_arg(args, int), direct);
		else if (direct->conv_spec == 'u' || direct->conv_spec == 'x' || direct->conv_spec == 'X')
			*result += ft_utobase_directiv(va_arg(args, unsigned int) ,direct);
		else if (direct->conv_spec == '%')
			*result += ft_putchar_directiv(direct->conv_spec, direct);
		ft_initialize_struct(direct);
	}
	return (*result);
}

int	ft_printf(const char *format, ...)
{
	va_list				args;
	size_t				result;
	t_directiv	direct;

	va_start(args, format);
	result = 0;
	ft_initialize_struct(&direct);
	print_directives(format, args, &result, &direct);
	va_end(args);
	return (result);
}

int main ()
{
	char	ch = '&';
	char	*s = "|str|";
	int		integer = -1234567;
	unsigned int	unint = 4294967295;
	unsigned	result;

	printf("my  words count: %d\n",ft_printf("aa %-8c %-8.2s %*s %20p %d %u %x % X %%\na",
			ch, s, 8, s, &unint, integer, unint, unint, unint));
	result = printf("aa %-8c %-8.2s %*s %20p %d %u %x %X %%\na",
			ch, s, 8, s, &unint, integer, unint, unint, unint);
	printf("std words count: %d", result);
}