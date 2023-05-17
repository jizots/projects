#include <stdio.h>

void 	ft_putnbr(int a)
{
	printf("%d\n", a);
}

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}

int	main(void)
{
	int tab[]={1,2,3,5,42,31,0};
	ft_foreach(tab, 7, &ft_putnbr);
	return (0);
}