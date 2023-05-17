#include <unistd.h>
void	printint(int a)
{
	int temp;
	if (a < 10)
	{
		write(1, "0", 1);
		a += '0';
		write(1, &a, 1);
	}
	else
	{
		temp = (a / 10) + '0';
		write (1, &temp, 1);
		a = a % 10 + '0';
		write (1, &a, 1);
	}
}

void	ft_comb2()
{
	int left;
	int right;

	left = 0;
	while (left < 99)
	{
		right = left + 1;
		while (right < 100)
		{
			printint(left);
			write(1, " ", 1);
			printint(right);
			if (left == 98 && right == 99)
				break ;
			write(1, ", ", 2);
			right++;
		}
		left++;
	}
}

int	main(void)
{
	ft_comb2();
	return 0;
}