#include "pipex.h"

int	ft_free_matrix(char **matrix, int flag_error)
{
	size_t	i;

	if (matrix != NULL)
	{
		i = 0;
		while (matrix[i] != NULL)
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
	if (flag_error != 0)
		ft_mes_error("Error. Fail allocate memory.\n");
	return (-1);
}