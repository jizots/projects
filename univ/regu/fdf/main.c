#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*list_d;

	if (ac != 2)
		write(1, "Entry like './fdf filename'\n", 28);
	else
	{
		list_d = ft_get_map(av[1], &list_d);
while(list_d != NULL)
{
printf("axis:%zu  ordinate:%zu  alti:%d  color:%u\n", list_d->axis, list_d->ordinate, list_d->altitude, list_d->color);
list_d = list_d->next;
}
	}
}