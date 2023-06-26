#include "pipex.h"

extern char	**environ;

char	**ft_search_envpaths(char ***matrix_path)
{
	size_t	i;

	i = 0;
	while(environ[i])
	{
		if (ft_strncmp(environ[i], "PATH=", 5) == 0)
		{
			*matrix_path = ft_split(&environ[i][5], ':');
			if (*matrix_path == NULL)
				ft_free_allocates(NULL, NULL, NULL, 1);
			return (*matrix_path);
		}
		i++;
	}
	ft_mes_error("Error: PATH= is not found.");
	return (NULL);
}