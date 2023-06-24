#include "pipex.h"

int	ft_free_matrix(char **matrix1, char **matrix2, int flag_error)
{
	size_t	i;

	if (matrix1 != NULL)
	{
		i = 0;
		while (matrix1[i] != NULL)
			free(matrix1[i++]);
		free(matrix1);
	}
	if (matrix2 != NULL)
	{
		i = 0;
		while (matrix2[i] != NULL)
			free(matrix2[i++]);
		free(matrix2);
	}
	if (flag_error != 0)
		ft_mes_error("Error. Fail allocate memory.\n");
	return (-1);
}