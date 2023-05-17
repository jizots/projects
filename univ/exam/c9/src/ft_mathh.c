#include <errno.h>
#include <math.h>
#include <stdio.h>

int power_10(int power)
{
	int	result;

	result = 1;
    if (power == 0)
        return (1);
    while(power--)
        result = result * 10;
    return (result);
}

//can use only not include minus
int	power_num(int num, int power)
{
	int	result;

	result = 1;
	if (power == 0 || num == 1)
		return (1);
	while (power--)
	{
		result = num * result;
	}
	return (result);
}