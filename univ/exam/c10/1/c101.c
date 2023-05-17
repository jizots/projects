#include "ft101.h"

void	ft_putstrerr(char *command_name, char *ref_item)
{
	ft_putstr(command_name);
	write(1, ": ", 2);
	ft_putstr(basename(ref_item));
	write(1, ": ", 2);
	ft_putstr(strerror(errno));
}

int put_file_cont(char *filename, char *command_name)
{
    int     fd;
    size_t  bytesread;
    char    buffer[1024];

	errno = 0;
    fd = open(filename, O_RDONLY);
    if (errno != 0)
	{
		ft_putstrerr(command_name, filename);
		return (-1);
	}
	while(errno == 0)
    {
		bytesread = read(fd, buffer, 1024);
		if (errno != 0)
		{
			ft_putstrerr(command_name, filename);
			return (-1);
		}
		if (bytesread > 0)
			ft_putnstr(buffer, bytesread);
		else
			break ;
    }
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	int	i;
	char	*command_name;
	
	command_name = "cat";
	i = 1;
	while(i < ac)
	{
		if (put_file_cont(av[i], command_name) == -1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}