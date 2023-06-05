#include "printf.h"

int	ft_putnstr(const char *str, size_t n)
{
	if (str == NULL)
		return (-1);
	while(n-- != 0 && *str != '\0')
	{
		if (write(1, str++, 1) == -1)
			return (-1);
	}
	return (0);
}
