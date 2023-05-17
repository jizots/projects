#ifndef RU2_H
#define RU2_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


typedef struct
{
	size_t	newline;
	size_t	i;
	int		max_spell;
}	t_culc_dict;


typedef struct s_numbers
{
	struct s_numbers	*next;
	int					number;
	char				*spell;
} t_numbers;

int	ft_atoi(char **av, unsigned int *input_num, int flag);
int	ft_myread(unsigned int input_num, int flag, int fd);
void	ft_putnbr(t_numbers *t_dict, int input_num);
int	len_spell;

#endif