#include <stdio.h>
#include <string.h>
#include <unistd.h>

int count = 0;

void	printQueen(int *result)
{
	int	row;
	char	c;

	row = 0;
	while (row < 10)
	{
		c = result[row] + '0';
		write(1, &c, 1);
		row++;
	}
	write (1, "\n", 1);
    count++;
}

void	change_board_ex(int board[10][10], int row, int col, int d)
{
	int k;

	k = 0;
	if (row + col < 10)
        while (k <= col)
        {
            board[row + k][col - k] += d;     /* lower left direction (when row +col < n) */
            k++;
        }
    else
        while (k < 10 - row)
        {
            board[row + k][col - k] += d;     /* lower left direction (when row+col >= n) */
            k++;
        }
}

/* add 'd' to x/y-axis(row,col) & lower diagonal-axis location*/
void changeBoard(int board[10][10], int row, int col, int d)
{
    int k;

    k = 0;
    while (k < 10)
    { 
        board[row][k] += d;             /* x-axis */
        board[k][col] += d;             /* y-axis */
        k++;
    }
	k = 0;
    if (row > col)
        while (k < 10 - row)
        {
            board[row + k][col + k] += d;   /* lower right direction (when row > col) */
            k++;
        }
    else
        while (k < 10 - col)
        {
            board[k + row][k + col] += d;   /* lower right direction (when row <= colのとき) */
            k++;
        }
	change_board_ex(board, row, col, d);
}

/* set location(gradually increment) of No_row of queen，and call setQueen(queen, board, row+1).
　if row == 10 print result*/
void setQueen(int queen[], int board[10][10], int row, int n)
{
    int col;

    if (row == n)
    {                              /*solve ploblem*/
        printQueen(queen);
        return ;
    }
    col = 0;
    while (col < n)
    {
        if (board[row][col] == 0)
        {                /* (row,col) の位置に置けるならば */
            queen[row] = col;                      /* (row,col) の位置にクイーンを置く */
            changeBoard(board, row, col, +1);      /* (row,col) から縦横斜めの方向のboard値を+1する */
            setQueen(queen, board, row + 1, n);       /* row+1 行目のクイーンの位置を決める */
            changeBoard(board, row, col, -1);      /* (row,col) から縦横斜めの方向のboard値を元に戻す */
        }
        col++;
    }
}

void findSolution()
{
    int queen[10];
    int board[10][10]={0};
    int n;
    int row;

    row = 0;
    n = 10;
    setQueen(queen, board, row, n);
}

int main()
{
    findSolution();
    printf("%d",count);
}
