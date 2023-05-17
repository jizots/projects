#include "ru00.h"

int	main(void)
{
	int	check_num;

	check_num = rush(200 ,200);
	if (check_num < 0)
		puts("please enter num upper one");
	return (0);
}