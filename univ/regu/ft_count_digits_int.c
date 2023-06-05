#include "printf.h"

unsigned short	ft_count_digits_int(int num)
{
	int	count_digits;

	count_digits = 0;
	if (num == -2147483648)
		return (11);
	else if (num < 0)
	{
		count_digits++;
		num = -num;
	}
	if (num == 0)
		count_digits++;
	while (num)
	{
		count_digits++;
		num = num / 10;
	}
	return (count_digits);
}
