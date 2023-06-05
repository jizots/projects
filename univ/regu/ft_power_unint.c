#include "printf.h"

size_t	power_unint(size_t num, size_t power)
{
	size_t	result;

	result = 1;
	if (power == 0 || num == 1)
		return (1);
	while (power--)
	{
		result = num * result;
		if (result % num != 0)
			return (0);
	}
	return (result);
}

// int main()
// {
// 	size_t	num = 15;
// 	size_t	power = 0;

// 	printf("%zu", power_unint(num, power));
// }