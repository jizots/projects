#include "printf.h"

int	ft_putchar_repeat(char c, size_t num_repeat)
{
	size_t	i;

	i = num_repeat;
	while (i--)
	{
		if (write (1, &c, 1) == -1)
			return (-1);
	}
	return (num_repeat);
}