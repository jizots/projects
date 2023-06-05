#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

//for func
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

//for verify
#include <stdio.h>

//define
#define SIZE_READ 5

//struct


//prototype
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

#endif