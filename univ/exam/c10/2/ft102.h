#ifndef FT102_H
#define FT102_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

size_t ft_strlen(const char *str);
char *ft_strncat(char *dest, const char *src, size_t n);
int	ft_putstr(char *str);
size_t	ft_putnstr(char *str, size_t n);
int	ft_putchar(const char c);
int	ft_atoi(char *src);

#endif