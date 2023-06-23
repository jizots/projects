#include "pipex.h"

extern char	**environ;

int		ft_exec_command(char *ab_path, char **option, char *insorce)
{
	int	fd;

	fd = open(insorce, O_RDONLY);
	if (fd < 0)
		return (-1);
}
