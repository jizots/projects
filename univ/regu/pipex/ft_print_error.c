#include "pipex.h"

int	ft_mes_error(char *message)
{
	write (STDERR_FILENO, message, ft_strlen(message));
	return (EXIT_FAILURE);
}

int		ft_print_perror(char *original_message)
{
	perror(original_message);
	return (EXIT_FAILURE);
}
