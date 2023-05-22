#include <stdio.h>
size_t ft_strlen(const char *str);
int	base_check(char *base);
size_t	str_check(char *str, char *base);
int	convert_int(char *str, char *base, size_t len_base, size_t len_str);
int	ft_atoi_base(char *str, char *base);
int power_10(int power);
int	power_num(int num, int power);
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
void ft_swap_int(int *x, int *y);
size_t ft_strlen(const char *str);
int	ft_numlen_int(int num);
int	ft_strcmp(const char *s1, const char *s2);
char *ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
const char	*ft_strstr(const char *haystack, const char *needle);
void	*memcpy(void *dest, const void *src, size_t n);