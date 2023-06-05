#include "printf.h"

int	ft_putchar(const char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (c);
}
