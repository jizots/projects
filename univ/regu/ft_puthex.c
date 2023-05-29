#include "printf.h"

void	ft_puthex(long long num, const int flag_upper)
{
	char	c;

	if (num / 16)
		ft_puthex(num / 16, flag_upper);
	num = num % 16;
	if (0 <= num && num <=9)
		c = num + '0';
	else
	{
		c = num - 10 + 'a';
		if (flag_upper != 0)
			c = ft_toupper(c);
	}
	ft_putchar(c);
}

// int main()
// {
// 	ft_puthex(0, 0);
// 	puts("");
// 	ft_puthex(17, 0);
// }