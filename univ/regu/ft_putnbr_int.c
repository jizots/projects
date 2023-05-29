#include "printf.h"

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
