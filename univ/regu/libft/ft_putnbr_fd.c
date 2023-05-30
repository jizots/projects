/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:32:47 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/20 10:32:50 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	temp;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n != 0)
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		temp = (n % 10) + '0';
		write(fd, &temp, 1);
	}
}

// int main()
// {
// 	int fd;
// 	fd = open("inputfile", O_WRONLY);
// 	if (fd == -1)
// 		puts("error");
// 	ft_putnbr_fd(0, fd);
// 	ft_putchar_fd('\n', fd);
// 	ft_putnbr_fd(-2147483648, fd);
// 	ft_putchar_fd('\n', fd);
// 	ft_putnbr_fd(2147483647, fd);
// 	ft_putchar_fd('\n', fd);
// 	ft_putnbr_fd(123, fd);
// 	ft_putchar_fd('\n', fd);
// 	close(fd);
// }