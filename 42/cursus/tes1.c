#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;
	size_t			i;

	if (n == 0)
		return (NULL);
	str = (unsigned char*)s;
	c1 = (unsigned char)c;
	i = 0;
	while (str[i] != c1 && i < n)
		i++;
	if (i == n)
		return (NULL);
	else
		return ((void*)&str[i]);
}

int main(void) {
  char s1[] = "123ab\0 *cdef";
  char c = '*';

	printf("%s %s", (char*)memchr(s1, (int)c, 11), (char*)ft_memchr(s1, (int)c, 11));
}