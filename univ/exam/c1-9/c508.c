#include <unistd.h>
#include <stdio.h>

void	print_array(int *queen, int *count)
{
	int	i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = queen[i++] + '0';
		write(1, &c, 1);
	}
	write (1, "\n", 1);
	*count += 1;
}

void	fill_map(int map[10][10], int row, int col, int d)
{
	int	k;

	k = 0;
	while (k < 10)
	{
		map [row][k] += d;
		map [k][col] += d;
		k++;
	}
	k = 0;
	if (row + col < 10) //lower left direction
		while (k <= col)
		{
			map[row + k][col - k] += d;
			k++;
		}
	else
		while (row + k < 10)
		{
			map[row + k][col - k] += d;
			k++;
		}
	k = 0;
	if (col < row) //lower right direction
		while (k < 10 - row)
		{
			map[row + k][col + k] += d;
			k++;
		}
	else
		while (k < 10 - col)
		{
			map[row + k][col + k] += d;
			k++;
		}
}

void	locate_queen(int map[10][10], int queen[10], int *count, int row)
{
	int	col;

	if (row == 10)
	{
		print_array(queen, count);
		return ;
	}
	col = 0;
	while (col < 10)
	{
		if (map[row][col] == 0)
		{
			queen[row] = col;
			fill_map(map, row, col, 1);
			locate_queen(map, queen, count, row + 1);
			fill_map(map, row, col, -1);
		}
		col++;
	}
}

int	ten_queen(void)
{
	int	count;
	int	map[10][10];
	int	queen[10];
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	locate_queen(map, queen, &count, 0);
	return (count);
}

int main(void)
{
    printf("%d",ten_queen());
}