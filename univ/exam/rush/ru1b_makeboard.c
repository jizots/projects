#include "ru1b.h"

int add_numbuil(int **board, int row , int col, int *max_height)
{
	if (board[row][col] > *max_height)
	{
		*max_height = board[row][col];
		return (1);
	}
	return (0);
}

int	num_of_building(int **board, const int hint[], int i, int moveto, int len_side)
{
	int	num_building;
	int	max_height;
	int	row;
	int	col;

	num_building = 1;
	if (i < len_side)
	{
		row = 0;
		col = i;
		max_height = board[row][col];
		while (row < len_side)
		{
			num_building = num_building + add_numbuil(board, row, col, &max_height);
			row = row + moveto;
		}
	}
	else if (i < len_side * 2)
	{
		row = len_side - 1;
		col = i - len_side;
		max_height = board[row][col];
		while (row >= 0)
		{
			num_building = num_building + add_numbuil(board, row, col, &max_height);
			row = row + moveto;
		}
	}
	else if (i < len_side * 3)
	{
		row = i - (len_side * 2);
		col = 0;
		max_height = board[row][col];
		while (col < len_side)
		{
			num_building = num_building + add_numbuil(board, row, col, &max_height);
			col = col + moveto;
		}
	}
	else if (i < len_side * 4)
	{
		row = i - (len_side * 3);
		col = len_side - 1;
		max_height = board[row][col];
		while (col >= 0)
		{
			num_building = num_building + add_numbuil(board, row, col, &max_height);
			col = col + moveto;
		}
	}
	if (hint[i] == num_building)
		return (0);
	else
		return (-1);
}

int	check_sky(int **board, const int hint[], int i, int len_side)
{
puts("check sky");
ft_print_board(board, len_side);
	while (i < len_side)
	{
		if (num_of_building(board, hint, i++, 1, len_side) == -1)
			return (-1);
	}
	while (i < len_side * 2)
	{
		if (num_of_building(board, hint, i++, -1, len_side) == -1)
			return (-1);
	}
	while (i < len_side * 3)
	{
		if (num_of_building(board, hint, i++, 1, len_side) == -1)
			return (-1);
	}
	while (i < len_side * 4)
	{
		if (num_of_building(board, hint, i++, -1, len_side) == -1)
			return (-1);
	}
	return (0);
}

int	is_used(int **board, int row, int col, int i)
{
	int k;

	k = 0;
	while (k < row)
	{
		if (board[k][col] == i)
			return (-1);
		k++; 
	}
	k = 0;
	while (k < col)
	{
		if (board[row][k] == i)
			return (-1);
		k++;
	}
	return (0);
}

int	make_board(int **board, int row, int col, const int *hint, const int len_side)
{
	int	i;

	i = 1;
	if (row < len_side)
	{
		if (col < len_side)
		{
			while(i < len_side + 1)
			{
				if(is_used(board, row , col, i) == 0)
				{
					board[row][col]	= i;
					if (row == (len_side - 1) && col == (len_side - 1) && check_sky(board, hint, 0, len_side) == 0)
						return (0);
					if (make_board(board, row, col + 1, hint, len_side) == 0)
						return (0);
				}
				i++;
			}
			if (i == len_side + 1)
				return (-1);
		}
		if (make_board(board, row + 1, 0, hint, len_side) == 0)
			return (0);
	}
	return (-1);
}