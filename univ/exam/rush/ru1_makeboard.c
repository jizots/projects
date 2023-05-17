#include "ru1.h"

int add_numbuil(int board[][4], int row , int col, int *max_height)
{
	if (board[row][col] > *max_height)
	{
		*max_height = board[row][col];
		return (1);
	}
	return (0);
}

int	num_of_building(int board[][4], const int hint[], int i, int moveto)
{
	int	num_building;
	int	max_height;
	int	row;
	int	col;

	num_building = 1;
	if (i < 4)
	{
		row = 0;
		col = i;
		max_height = board[row][col];
		while (row < 4)
		{
			num_building = num_building + add_numbuil(board, row, col, &max_height);
			row = row + moveto;
		}
	}
	else if (i < 8)
	{
		row = 3;
		col = i - 4;
		max_height = board[row][col];
		while (row >= 0)
		{
			num_building = num_building + add_numbuil(board, row, col, &max_height);
			row = row + moveto;
		}
	}
	else if (i < 12)
	{
		row = i - 8;
		col = 0;
		max_height = board[row][col];
		while (col < 4)
		{
			num_building = num_building + add_numbuil(board, row, col, &max_height);
			col = col + moveto;
		}
	}
	else if (i < 16)
	{
		row = i - 12;
		col = 3;
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

int	check_sky(int board[][4], const int hint[], int i)
{
	while (i < 4)
	{
		if (num_of_building(board, hint, i++, 1) == -1)
			return (-1);
	}
	while (i < 8)
	{
		if (num_of_building(board, hint, i++, -1) == -1)
			return (-1);
	}
	while (i < 12)
	{
		if (num_of_building(board, hint, i++, 1) == -1)
			return (-1);
	}
	while (i < 16)
	{
		if (num_of_building(board, hint, i++, -1) == -1)
			return (-1);
	}
	return (0);
}

int	is_used(int board[][4], int row, int col, int i)
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

int	make_board(int board[][4], int row, int col, const int hint[])
{
	int	i;

	i = 1;
	if (row < 4)
	{
		if (col < 4)
		{
			// board[row][col] = 0;
			while(i < 5)
			{
				if(is_used(board, row , col, i) == 0)
				{
					board[row][col]	= i;
					if (row == 3 && col == 3 && check_sky(board, hint, 0) == 0)
						return (0);
					if (make_board(board, row, col + 1, hint) == 0)
						return (0);
				}
				i++;
			}
			if (i == 5)
				return (-1);
		}
		if (make_board(board, row + 1, 0, hint) == 0)
			return (0);
	}
	return (-1);
}