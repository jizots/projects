#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	make_board(int **board, int row, int col, const int hint[], int len_side);
void	ft_print_board(int **board, size_t len_side);