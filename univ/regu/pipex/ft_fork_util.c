#include "pipex.h"

int	ft_wait_judge_child(int pid)
{
	int	status;

	if (pid == -1)
		return (ft_print_perror("fork"));
	else
	{
		pid = wait(&status);
		if (pid == -1)
			return (ft_print_perror("wait"));
		if (WIFEXITED(status) && WEXITSTATUS(status))
			return (ft_mes_error("Child process end with error."));
		return (0);
	}
}