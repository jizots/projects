#include "ru2.h"

int	main(int ac, char **av)
{
	unsigned int	input_num;
	int				fd;

	input_num = 0;
	if (ac == 2 && ft_atoi(av, &input_num, 0) != -1)
	{
		fd = open("dictionary", O_RDONLY);
		if (fd == -1 || ft_myread((input_num), 0, fd) < 0)
			write(1, "Dict-Error\n", 11);
	}
	else if (ac == 3 && ft_atoi(av, &input_num, 1) != -1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1 || ft_myread((input_num), 1, fd) < 0)
			write(1, "Dict-Error\n", 11);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}