#include "pipex.h"

extern char	**environ;

char	**ft_search_envpaths(void)
{
	size_t	i;

	i = 0;
	while(environ[i])
	{
		if (ft_strncmp(environ[i], "PATH=", 5) == 0)
			return (ft_split(&environ[i][5], ':'));
		i++;
	}
	ft_mes_error("Error: PATH is not found in Environment args.");
	return (NULL);
}