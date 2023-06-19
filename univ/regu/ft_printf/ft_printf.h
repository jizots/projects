/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:17:35 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:17:42 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//include header
# include <stdlib.h> // formalloc
# include <errno.h> // for malloc
# include <stdarg.h> //for va_list
# include <limits.h> //for atoi
# include <unistd.h> //for write

//for verify
# include <stdio.h>

//typedef
typedef struct s_directiv
{
	int		f_hash;
	int		flag_zero;
	int		flag_minus;
	int		flag_space;
	int		flag_plus;
	int		flag_apost;
	int		flag_widastr;
	int		flag_precastr;
	int		width;
	int		preci;
	char	length_modifier[3];
	char	conv_spec;
	int		flag_wait;
}	t_directiv;

//prototype
int				ft_atoi(const char *src);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
unsigned short	ft_count_digits_int(int num);
char			*ft_itoa_input(int n, char *dest, unsigned int digit_int);
char			*ft_itoa(int n);
unsigned short	ft_num_of_digits_int(int num);
char			*ft_itoa_input(int n, char *dest, unsigned int digit_int);
char			*ft_itobase(int n, char *base);
void			*ft_memset(void *b, int c, size_t len);
int				ft_printf(const char *format, ...);
t_directiv		*ft_initialize_struct(t_directiv *direct);
int				ft_capt_directiv(const char *str, t_directiv *direct);
void			ft_putadrs(char *hex);
size_t			ft_putadrs_directiv(void *adrs, t_directiv *direct);
int				ft_putchar(const char c);
size_t			ft_putchar_directiv(char c, t_directiv *direct);
void			ft_putnbr_space_plus(t_directiv *direct, int *len_puts,
					char *p_n);
void			ft_putnbr_directiv6(t_directiv *direct, int *len_puts,
					char *p_n);
int				ft_putchar_repeat(char c, size_t num_repeat);
size_t			ft_putnbr_directiv(int n, t_directiv *direct);
void			ft_putnbr_int(int nbr);
int				ft_putnstr(const char *str, size_t n);
size_t			ft_put_repeat_str(char ch_repeat, size_t size_repeat,
					char *str);
int				ft_putstr(const char *str);
size_t			ft_putstr_directiv(char *str, t_directiv *direct);
size_t			ft_put_str_repeat(char *str, char ch_repeat,
					size_t size_repeat);
size_t			ft_puts_utobase(t_directiv *direct, size_t len_puts,
					char *p_str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *str);
int				ft_str_only_chr(char *str);
int				ft_toupper(int c);
char			*ft_utobase(unsigned long n, char *base);
size_t			ft_utobase_directiv(unsigned long n, t_directiv *direct);

#endif
