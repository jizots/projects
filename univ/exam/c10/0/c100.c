#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_putnstr(char *str, size_t n)
{
	int	i;

	i = 0;
	while(str[i] && n--)
	{
		if (write(1,&str[i], 1) == -1)
			return (-1);
		i++;
	}
	if (n)
		return (n);
	return (0);
}

int read_binary_file(char *av)
{
    int     fd;
    size_t  bytesread;
    char    buffer[1024];
    int     result;

    result = 0;
    fd = open(av, O_RDONLY);
    if (fd == -1)
        result = -1;
    while(1 && result == 0)
    {
        bytesread = read(fd, buffer, 1024);
        if (bytesread > 0)
           ft_putnstr(buffer, bytesread);
        else
            break ;
    }
    if (bytesread == 0)
        result = 0;
    close(fd);
    return (result);
}

int main(int ac, char **av)
{
    if (ac == 1)
        write(1, "File name missing.\n", 19);
    else if (ac == 2 && read_binary_file(av[1]) == -1)
        write(1, "Can not read file.\n", 19);
    else if (ac > 2)
        write(1, "Too many arguments.\n", 20);
    return (0);
}