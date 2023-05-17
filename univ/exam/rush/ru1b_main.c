#include "ru1b.h"

int ft_avtoi(char **av, int *hint, int len_av)
{
	int	i;
	int	i_hint;

	i = 0;
	i_hint = 0;
	while (i < len_av)
	{
		if (i % 2 == 0)
		{
			hint[i_hint] = av[1][i] - 48;
			if (1 > hint[i_hint] || hint[i_hint] > (len_av / 4))
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

void	ft_print_board(int **board, size_t len_side)
{
	size_t	i, j;
	char c;

	i = 0;
	while (i < len_side)
	{
		j = 0;
		while(j < len_side)
		{
			c = board[i][j] + '0';
			write (1, &c, 1);
			if (j++ < len_side - 1)
				write(1, " ", 1);
		}
		i++;
		write (1, "\n", 1);
	}
}

int	check_command_line(int ac, char **av, int **hint, size_t *len_hint)
{
	size_t	len_av;

	if (ac != 2)
		return (-1);
	len_av = 0;
	while (av[1][len_av])
		len_av++;
	*len_hint = (len_av + 1) / 2;
	if (*len_hint % 4 != 0)
		return (-1);
	*hint = malloc(sizeof(int) * (*len_hint));
	if (*hint == NULL)
		return (-1);
	if (ft_avtoi(av, *hint, len_av) < 0)
		return (-1);
	return (0);
}

int	main(int ac, char *av[])
{
	int		*hint;
	size_t	len_hint;
	size_t	len_side;
	int 	**board;
	int		i;
	int		row;
	int 	col;

	if (check_command_line(ac, av, &hint, &len_hint) < 0)
	{
		write (1, "Error\n", 6);
		free(hint);
		return (0);
	}
	len_side = len_hint / 4;	
printf("%d ",len_side);
	board = malloc (sizeof(int*) * len_side);
	if (board == NULL)
	{
		free(hint);
		return (0);
	}
	i = 0;
	while (i < (int)len_side)
	{
		board[i] = malloc(sizeof(int) * len_side);
		if (board[i] == NULL)
		{
			while (i >= 0)
				free(board[i--]);
			return (0);
		}
		i++;
	}
	row = 0;
	col = 0;
	if (make_board(board, row, col, hint, (int)len_side) == 0)
	{
		ft_print_board(board, len_side);
puts("solve");
	}
	else
		write (1, "Error\n", 6);
	return (0);
}