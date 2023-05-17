#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_putstr(char *str)
{
	if (str == NULL)
		return (-1);
	int i = 0;
	while(str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (0);
}

size_t	ft_putnstr(char *str, size_t n)
{
	int i = 0;
	while(str[i] && n--)
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	if (n)
		return (n);
	return (0);
}

int	ft_putchar(const char c)
{
	int	bytes;

	bytes = write(1, &c, 1);
	if (bytes == -1)
		return (EOF);
	return (c);
}

void	ft_putchar_repeat(char c, int num)
{
	while (num--)
		write (1, &c, 1);
}

void	ft_putnbr_int(int nbr)
{
	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr_int(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
	else if (nbr >= 0)
		ft_putchar(nbr + '0');
}

void	ft_putnbr_unsignedint(unsigned int nbr)
{
	if (nbr >= 10)
	{
		ft_putnbr_unsignedint(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
	else if (nbr >= 0)
		ft_putchar(nbr + '0');
}

void	ft_putnbr_longlong(long long nbr)
{
	if (nbr == -9223372036854775807LL - 1)
		write(1, "-9223372036854775808", 20);
	else if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr_longlong(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
	else if (nbr >= 0)
		ft_putchar(nbr + '0');
}

void	ft_puthex(long long num, const int upperflag)
{
	char	c;

	if (num / 16)
		ft_puthex(num / 16, upperflag);
	num = num % 16;
	if (0 <= num && num <=9)
		c = num + '0';
	else
	{
		if (upperflag == 0)
			c = num - 10 + 'a';
		else
			c = num - 10 + 'A';
	}
	write(1, &c, 1);
}

//ft_print_address.
void	ft_print_address(void *add)
{
	uintptr_t	address;

	address = (uintptr_t)add;
	write(1, "0x", 2);
	ft_puthex(address, 0);
}

//ft_putdouble
void	put_fractional(double num, int digits)
{
	int		integer;
	char	c;

	while (digits--)
	{
		num = num * 10;
		integer = (int)num;
		if (digits == 0 && (((int)(num * 10)) % 10) >= 5)
			integer += 1;
		c = integer +  '0';
		write (1, &c, 1);
		num = num - integer;
	}
}

void	ft_putdouble(double num, int digit)
{
	long long	integer;

	integer = (long long)num;
	ft_putnbr_longlong(integer);
	write(1, ".", 1);
	num = num - integer;
	if (num < 0)
		num = -num;
	put_fractional(num, digit);
}

//ft_putdouble2
typedef struct
{
	uint8_t		sign;
	uint8_t		exp;
	uint32_t	frac;
}	t_sfloat;

