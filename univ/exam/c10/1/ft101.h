#ifndef FT101_H
#define FT101_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

int	ft_putstr(char *str);
size_t	ft_putnstr(char *str, size_t n);
int	ft_putchar(const char c);
void	ft_putchar_repeat(char c, int num);
void	ft_putnbr_int(int nbr);
void	ft_putnbr_unsignedint(unsigned int nbr);
void	ft_putnbr_longlong(long long nbr);
void	ft_puthex(long long num, const int upperflag);
void	ft_print_address(void *add);
void	put_fractional(double num, int digits);
void	ft_putdouble(double num, int digit);

#endif