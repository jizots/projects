#include "printf.h"

int	ft_putstr(const char *str)
{
	if (str == NULL)
		return (-1);
	while(*str)
	{
		if (write(1, str++, 1) == -1)
			return (-1);
	}
	return (0);
}
