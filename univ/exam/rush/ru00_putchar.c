#include "ru00.h"

int	ft_putchar(char	*c)
{
	write(1, c, 1);
	return ((int)*c);
}