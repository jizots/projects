#include "pipex.h"

int	ft_wait_judge_child(int pid, int *out_pipefd)
{
	int	status;

	if (pid == -1)
		return (ft_print_perror("fork"));
	else
	{
		if (out_pipefd != NULL)
		{
			if (close(out_pipefd[1]) == -1)
				exit(ft_print_perror("close out_pipefd[1]-main"));
		}
		pid = wait(&status);
		if (pid == -1)
			return (ft_print_perror("wait"));
		if (WIFEXITED(status) && WEXITSTATUS(status))
			return (ft_mes_error("Child process end with error."));
		return (0);
	}
}