#include "ft_printf.h"

char	*fill_null(char *str, size_t size)
{
	while (size--)
		str[size] = '\0';
	return (str);
}
