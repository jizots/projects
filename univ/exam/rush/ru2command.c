#include "ru2.h"

int	ft_atoi(char **av, unsigned int *input_num, int flag)
{
	int	read_ac;
	long long temp;
	int	i;

	if (flag == 0)
		read_ac = 1;
	else
		read_ac = 2;
	i = 0;
	while (av[read_ac][i])
	{
		if ('0' > av[read_ac][i] || av[read_ac][i] > '9')
			return (-1);
		temp = *input_num * 10 + (av[read_ac][i] - '0');
		if (temp > 2147483647)
			return (-1);
		*input_num = temp;
		i++;
	}
	return (0);
}