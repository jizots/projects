#include "pipex.h"

int	ft_mes_error(char *message)
{
	write (STDERR_FILENO, message, ft_strlen(message));
	return (-1);
}

int		ft_print_perror(char *original_message)
{
	perror(original_message);
	return (-1);
}
