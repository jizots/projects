#include <unistd.h>

int	ft_atoi(char *src)
{
	int i;
	int	minus;
	int	result;

	i = 0;
	while (src[i] == ' ')
		i++;
	minus = 0;
	while (src[i] == '-' || src[i] == '+')
	{
		if (src[i++] == '-')
			minus++;
	}
	result = 0;
	while ('0' <= src[i] && src[i] <= '9')
		result = result * 10 + (src[i++] - '0');
	if (minus % 2 == 0)
		return (result);
	return (-result);
}

int	addition(int a, int b)
{
	return (a + b);
}

int	subtraction(int a, int b)
{
	return (a - b);
}

int	multiplication(int a, int b)
{
	return (a * b);
}

int division(int a, int b)
{
	return (a / b);
}

int ft_remainder(int a, int b)
{
	return (a % b);
}

int	conv_op_int(char operator)
{
	if (operator == '+')
		return (0);
	if (operator == '-')
		return (1);
	if (operator == '*')
		return (2);
	if (operator == '/')
		return (3);
	else
		return (4);
}

void	ft_putnbr(int a)
{
	if (a == -2147483648)
		write (1, "-2147483648", 11);
	else if (a < 0)
	{
		write(1, "-", 1);
		a = -a;
		ft_putnbr(a);
	}
	else
	{
		if (a / 10 != 0)
			ft_putnbr(a / 10);
		a = a % 10 + '0';
		write (1, &a, 1);
	}
}

void	select_culc_func(char **av, char operator)
{
	int n1;
	int n2;
	int	op;
	int (*afp[5])(int, int);

	n1 = ft_atoi(av[1]);
	n2 = ft_atoi(av[3]);
	afp[0] = addition;
	afp[1] = subtraction;
	afp[2] = multiplication;
	afp[3] = division;
	afp[4] = ft_remainder;
	op = conv_op_int(operator);
	ft_putnbr((*afp[op])(n1, n2));
}

int	main(int ac, char *av[])
{
	char operator;

	operator = av[2][0];
	if (ac != 4)
		return (0);
	else if (operator != '+' && operator != '-'
		&& operator != '*' && operator != '/' && operator != '%')
		write (1, "0", 1);
	else if ((operator == '/' || operator == '%') && ft_atoi(av[3]) == 0)
	{
		if (operator == '/')
			write(1, "Stop : division by zero", 23);
		else
			write(1, "Stop : modulo by zero", 21);
	}
	else
		select_culc_func(av, operator);
	return (0);
}