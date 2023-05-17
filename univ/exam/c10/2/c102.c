#include "ft102.h"

int	ft_putstrerr(char *command_name, char *ref_item)
{
	if (command_name != NULL)
	{
		ft_putstr(command_name);
		write(1, ": ", 2);
	}
	if (ref_item != NULL)
	{
		ft_putstr(basename(ref_item));
		write(1, ": ", 2);
	}
	ft_putstr(strerror(errno));
	write(1, "\n", 1);
	return (errno);
}

long int	read_file_bytes(char *filename, char *command_name)
{
    size_t  bytesread;
	size_t	totalbytes;
    char    buffer[1024];
	int		fd;

	errno = 0;
	fd = open(filename, O_RDONLY);
	if (errno != 0)
		return (ft_putstrerr(command_name, filename));
	totalbytes = 0;
	while(errno == 0)
    {
		bytesread = read(fd, buffer, 1024);
		if (errno != 0)
			return (ft_putstrerr(command_name, filename));
		if (bytesread <= 0)
			break ;
		totalbytes = bytesread + totalbytes;
    }
	if (close(fd) == -1)
		return ft_putstrerr(command_name, filename);
	return (totalbytes);
}

char	*allocate_memory(const size_t bytes)
{
	char	*addr;

	addr = malloc(sizeof(char) * (bytes + 1));
	if (addr == NULL)
	{
		ft_putstrerr(NULL, NULL);
		return (NULL);
	}
	return (addr);
}

int	ft_copy_file(char *filename, char *command_name, char *dest)
{
	size_t  bytesread;
	char    buffer[1024];
	int		fd;

	errno = 0;
	fd = open(filename, O_RDONLY);
	if (errno != 0)
		return (ft_putstrerr(command_name, filename));
	while(errno == 0)
	{
		bytesread = read(fd, buffer, 1024);
		if (errno != 0)
			return (ft_putstrerr(command_name, filename));
		if (bytesread <= 0)
			break ;
		ft_strncat(dest, buffer, bytesread);
		dest = &dest[bytesread];
		dest[0] = '\0';
    }
	if (close(fd) == -1)
		return ft_putstrerr(command_name, filename);
	return (0);
}

void	ft_put_backn_cont(char *str, size_t len_str, size_t n)
{
	size_t	start_addr;

	if (len_str < n)
	{
		ft_putstr(str);
		return ;
	}
	start_addr = len_str - n;
	ft_putstr(&str[start_addr]);	
}

int main(int ac, char **av)
{
	int		i;
	char	*command_name;
	int 	bytesput;
	size_t	totalbytes;
	char	*dest;

	command_name = "tail";
	i = 3;
	bytesput = ft_atoi(av[2]);
	while(i < ac)
	{
		dest = NULL;
		totalbytes = read_file_bytes(av[i], command_name);
		if (errno == 0)
			dest = allocate_memory(totalbytes);
		if(dest != NULL)
			ft_copy_file(av[i], command_name, dest);
		if (errno == 0)
		{
			if (i + 2 > ac)
				write(1, "\n", 1);
			write(1, "==> ", 4);
			ft_putstr(av[i]);
			write(1, " <==\n", 5);
			ft_put_backn_cont(dest, totalbytes, (size_t)bytesput);
		}
		i++;
	}
	free(dest);
	return (0);
}