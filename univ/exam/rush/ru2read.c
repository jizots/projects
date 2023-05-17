#include "ru2.h"

void	ft_free_tdict(t_numbers *t_dict, int newline)
{
	int i;

	i = 0;
	while (i < newline)
	{
		free(t_dict[i++].spell);
	}
	free(t_dict);
}

void	ft_dict_atoi(char *buffer, t_numbers *t_dict, int bytesread)
{
	int	i;
	int	num;
	int	num_spell;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (i != 0)
			t_dict = t_dict->next;
		t_dict->number = 0;
		while ('0' <= buffer[i] && buffer[i] <= '9')
		{
			t_dict->number = t_dict->number * 10 + (buffer[i++] - '0');
		}
		while (buffer[i] == ' ') i++;
		while (buffer[i] == ':') i++;
		while (buffer[i] == ' ') i++;
		num_spell = 0;
		while (buffer[i] != '\n' && buffer[i] != '\0')
			t_dict->spell[num_spell++] = buffer[i++];
		t_dict->spell[num_spell] = '\0';
		while (buffer[i] == '\n') i++;
	}
}

t_numbers	*ft_swap_dict(t_numbers *current)
{
	t_numbers	*prev;
	t_numbers	*next;

	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

int	ft_verify_dict(t_numbers *t_dict)
{
	t_numbers	*current;
	int			fix_num;

	if (t_dict == NULL)
		return 0;
	fix_num = t_dict->number;
	current = t_dict->next;
	while (current)
	{
		if (fix_num == current->number)
			return (-1);
		current = current->next;
	}
	return (ft_verify_dict(t_dict->next));
}

void	ft_opendict_tinput(t_numbers *t_dict, int input_num)
{
	int		fd;
	int		i;
	char	buffer[1024];
	int		bytesread;

	if (t_dict == NULL)
		return ;
	fd = open ("dictionary", O_RDONLY);
	bytesread = read(fd, buffer, 1024);
	buffer[bytesread] = '\0';
	ft_dict_atoi(buffer, t_dict, bytesread);
	t_dict = ft_swap_dict(t_dict);
	if (ft_verify_dict(t_dict) == -1)
	{
		write(1, "Dict-Error\n", 11);
		return ;
	}
	ft_putnbr(t_dict, input_num);
	close(fd);
}

int	ft_create_tnumbers(int newline, int max_spell, int input_num)
{
	int	i;
	t_numbers	*t_dict;

	i = 0;
	t_dict = malloc(sizeof(t_numbers) * newline);
	if (t_dict == NULL)
		return (-1);
	while (i < newline)
	{
		t_dict[i].spell = malloc(sizeof(char) * (max_spell + 1));
		if (t_dict[i].spell == NULL)
		{
			ft_free_tdict(t_dict, newline);
			return (-1);
		}
		if (i != 0)
			t_dict[i - 1].next = &t_dict[i];
		t_dict[i].next = NULL;
		i++;
	}
	ft_opendict_tinput(t_dict, input_num);
	return (0);
}

int	ft_myread(unsigned int input_num, int flag, int fd)
{
	ssize_t		bytesread;
	char		buffer[1024];
	t_culc_dict	culc_dict;

	culc_dict.newline = 0;
	culc_dict.max_spell = 0;
	while ((bytesread = read (fd, buffer, 1024)) > 0)
	{
		culc_dict.i = 0;
		while (culc_dict.i < bytesread)
		{
			len_spell++;
			if (buffer[culc_dict.i++] == 10)
			{
				culc_dict.newline++;
				len_spell = 0;
			}
			if (culc_dict.max_spell < len_spell)
				culc_dict.max_spell = len_spell;
		}
	}
	close(fd);
	if (ft_create_tnumbers((int)culc_dict.newline + 1, culc_dict.max_spell, input_num) == -1)
		return (-1);
	return (0);
}