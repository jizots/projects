#include "ru1.h"

int ft_avtoi(char **av, int hint[])
{
	int	i;
	int	i_hint;

	i = 0;
	i_hint = 0;
	while (i < 31)
	{
		if (i % 2 == 0)
		{
			hint[i_hint] = av[1][i] - 48;
			if (1 > hint[i_hint] || hint[i_hint] > 4)
			{
				return (-1);
			}
			i_hint++;
		}
		else
		{
			if (av[1][i] != 32)
				return (-1);
		}
		i++;
	}
	return (0);
}

void	ft_print_board(int board[][4])
{
	int	i, j;
	char c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while(j < 4)
		{
			c = board[i][j] + '0';
			write (1, &c, 1);
			if (j++ < 3)
				write(1, " ", 1);
		}
		i++;
		write (1, "\n", 1);
	}
}

int	check_command_line(int ac, char **av, int hint[])
{
	if (ac != 2 || ft_avtoi(av, hint) < 0)
		return (-1);
	return (0);
}

int	main(int ac, char *av[])
{
	int	hint[16];
	int board[4][4] = {0};
	int	row;
	int col;

	if (check_command_line(ac, av, hint) < 0)
		write (1, "Error\n", 6);
	row = 0;
	col = 0;
	if (make_board(board, row, col, hint) == 0)
	{
		ft_print_board(board);
puts("solve");
	}
	else
		write (1, "Error\n", 6);
	return (0);
}