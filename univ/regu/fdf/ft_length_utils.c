#include "fdf.h"

double	ft_hypotenus_of_pytgrs(double x, double y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

int main()
{
	double	x;
	double	y;

	printf("hepotenus of x & y: %f\n", ft_hypotenus_of_pytgrs(sqrt(3),1));
}