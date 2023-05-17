#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
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
	int	i;

	i = 0;
	if (str == NULL)
	return (-1);
	while(str[i] && n--)
	{
		if (write(1,&str[i], 1) == -1)
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

int	ft_putstr_rev(char *str)
{
	int		len;

	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	while (len-- > 0)
		write (1, &str[len], 1);
	return (0);
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

//print bits of unsigned int.
int	count_unint_bits(unsigned x)
{
	int	count;

	count = 0;
	while (x)
	{
		if (x & 1U)
		{
			count++;
			x >>= 1;
		}
	}
	return (count);
}

int	int_bits(void)
{
	return (count_unint_bits(~0U));
}

void	putbids_unint(unsigned int x)
{
	int	i;

	i = int_bits() - 1;
	while (i >= 0)
	{
		if ((x >> i) & 1U)
			ft_putchar('1');
		else
			ft_putchar('0');
		i--;
	}	
}

//print bits of unsigned long long.
int	count_uint64_bits(uint64_t x)
{
	int	count;

	count = 0;
	while (x)
	{
		if (x & 1U)
		{
			count++;
			x >>= 1;
		}
	}
	return (count);
}

int	uint64_bits(void)
{
	return (count_uint64_bits(~0ULL));
}

void	putbids_uint64(uint64_t x)
{
	int	i;

	i = uint64_bits() - 1;
	while (i >= 0)
	{
		if ((x >> i) & 1U)
			ft_putchar('1');
		else
			ft_putchar('0');
		i--;
	}	
}

