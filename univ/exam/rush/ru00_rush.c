#include "ru00.h"


int	rush(int x, int y)
{
	int	iy;
	int	ix;

	if (x <= 0 || y <= 0)
		return (-1);
	iy = 0;
	while (iy < y)
	{
		ix = 0;
		while (ix < x)
		{
			if ((ix == 0 || ix == x - 1) && (iy == 0 || iy == y - 1))
				ft_putchar("o");
			else if ((iy == 0 || iy == y - 1) && (0 < ix && ix < x -1))
				ft_putchar("-");
			else if (ix == 0 || ix == x - 1)
				ft_putchar("|");
			else
				ft_putchar(" ");
			ix++;
		}
		write (1, "\n", 1);
		iy++;
	}
	return (0);
}