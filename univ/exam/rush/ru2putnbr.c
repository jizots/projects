#include "ru2.h"

void	ft_putsint(t_numbers *t_dict, int c)
{
	int	i;
	while (t_dict->number != c)
	{
		t_dict = t_dict->next;
		if (t_dict == NULL)
		{
			write(1, "Dict-Error\n", 11);
			return ;
		}
	}
	i = 0;
	while (t_dict->spell[i])
	{
		write(1, &t_dict->spell[i], 1);
		i++;
	}
	write(1, " ", 1);
}

void	ft_setputs(t_numbers *t_dict, int input)
{
	int	c;

	if (t_dict == NULL || input == 0)
		return ;
	while (t_dict->number > input)
		t_dict = t_dict->next;
	if (input >= 100)
	{
		c = ((int)(input / 100)) * 100;
		ft_setputs(t_dict->next, c / 100);
		ft_putsint(t_dict, 100);
		ft_setputs(t_dict->next, input % 100);
	}
	else if (input >= 20)
	{
		c = ((int)(input / 10)) * 10;
		ft_putsint(t_dict, c);
		ft_setputs(t_dict->next, input % 10);
	}
	else if (input >= 1)
		ft_putsint(t_dict, input);
}

void	ft_putnbr(t_numbers *t_dict, int input_num)
{
	int	i;

	if (t_dict == NULL)
		return ;
	if (input_num == 0)
	{
		write (1, "zero\n", 5);
		return ;
	}
	i = 0;
	if (input_num >= t_dict->number && input_num >=100)
	{
		ft_setputs(t_dict, input_num / t_dict->number);
		input_num = input_num % t_dict->number;
		ft_putsint(t_dict, t_dict->number);
	}
	else if (input_num < 100)
	{
		ft_setputs(t_dict, input_num);
		return ;
	}
	if (input_num != 0)
		ft_putnbr(t_dict->next, input_num);
}