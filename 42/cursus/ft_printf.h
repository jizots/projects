#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_putstr(const char *str);
size_t	ft_putnstr(char *str, size_t n);
int		ft_putchar(const char c);
int		ft_putstr_rev(char *str);
void	ft_putnbr_int(int nbr);
void	ft_print_address(void *add);
void	ft_putfloat(float f_num);
void	ft_putdouble(double d_num);
int		count_bits(unsigned x);//for debug
int		int_bits(void);
void	putbids_unint(unsigned int x);//for debug
int		count_uint64_bits(uint64_t x);//for debug
int		uint64_bits(void);
void	putbids_uint64(uint64_t x);//for debug
int		ft_atoi(const char *src);
int		convert_int(char *str, char *base, size_t len_base, size_t len_str);
size_t	str_check(char *str, char *base);
int		base_check(char *base);
int		ft_atoi_base(char *str, char *base);
unsigned short	ft_num_of_digits_int(int num);
size_t 	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, const char *src, size_t n);
int		power_num(int num, int power);
char	*power_2_revary(char *result, size_t power);
char	*add_num_of_revary(char *num, char *result);
char	*add_ary_of_frac(char *num, char *result);
char	*power_point5_ary(char *result, size_t power);
size_t	binary_to_size(char *binstr, size_t len_binstr);
char	*fill_null(char *str, size_t size);

#define SIZEFLOAT_INT 40
#define SIZEFLOAT_DECI 150
#define SIZEDOUBLE_INT 309
#define SIZEDOUBLE_DECI 1075

//To understand internal representation of float type. use union(share memory type).
typedef union
{
	float			value;
	unsigned int	bit_float;
}	t_ufloat;

//To understand internal representation of double type. use union(share memory type).
typedef union
{
	double		value;
	uint64_t	bit_double;
}	t_udouble;

//struct to contain % format option.
typedef struct
{
	char	flag[8];
	size_t	wide_field;
	size_t	accuracy;
	char	*length_modifiers;
	char	conv_spec;
	int		wait_flag;
} t_format_print;

typedef struct
{
	char	sign;
	char	exponent[8];
	char	fraction[23];
	int		exp_int;
	char	integer_bin[129];//For measure len, add one byte for NULL end.
	char	decimals_bin[151]; // same as above.
	char	rev_integer[SIZEFLOAT_INT];
	char	nor_decimals[SIZEFLOAT_DECI];
} t_sfloat;

typedef struct
{
	char	sign;
	char	exponent[11];
	char	fraction[52];
	int		exp_int;
	char	integer_bin[1025];//For measure len, add margin memory.
	char	decimals_bin[1075]; // same as above.
	char	rev_integer[SIZEFLOAT_INT];
	char	nor_decimals[SIZEFLOAT_DECI];
} t_sdouble;

#endif