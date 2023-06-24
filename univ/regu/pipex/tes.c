#include "pipex.h"

extern char **environ;


int	ft_wait_judge_child(int pid)
{
	int	status;

	if (pid == -1)
		return (ft_print_perror("fork"));
	else
	{
		pid = wait(&status);
puts("wait1");
		if (pid == -1)
			return (ft_print_perror("wait"));
		if (!(WIFEXITED(status)))
			return (ft_mes_error("Child process end with error."));
		return (0);
	}
}

int first_exec(int *in_pipefd, char **argv)
{
	int	fdr;

	fdr = open("file1", O_RDONLY);
	if (fdr < 0)
		exit(ft_print_perror("file1"));
	if (close(in_pipefd[0]) == -1)
		exit(ft_print_perror("close"));
	if (dup2 (fdr, STDIN_FILENO) == -1)
		exit(ft_print_perror("dup2"));
	if (dup2 (in_pipefd[1], STDOUT_FILENO) == -1)
		exit(ft_print_perror("dup2"));
	if (close (fdr) == -1)
		exit(ft_print_perror("close"));
	if (execve("/bin/cat", argv, environ) == -1)
		exit(ft_print_perror("execve"));//When [in_pipefd[1]] expect close?
	exit(EXIT_SUCCESS);
}

int	middle_exec(int *in_pipefd, int *out_pipefd, char **argv)
{
	int pid;
	int status;

	pid = fork();
    if (pid == 0)// 子プロセスの処理
	{
		if (close(in_pipefd[1]) == -1)
			exit(ft_print_perror("close"));
		if (close(out_pipefd[0]) == -1)
			exit(ft_print_perror("close"));
		if (dup2(in_pipefd[0], STDIN_FILENO) == -1)
			exit(ft_print_perror("dup2"));
		if (dup2(out_pipefd[1], STDOUT_FILENO) == -1)
			exit(ft_print_perror("dup2"));
		if (close(out_pipefd[1]) == -1)
			exit(ft_print_perror("close"));
		if (close(in_pipefd[0]) == -1)
			exit(ft_print_perror("close"));
		if (execve("/usr/bin/wc", argv, environ) == -1)
			exit(ft_print_perror("execve"));//When [out_pipefd[1]] & in_pipefd[0] expect close?
puts("execve error");
	}
	else if (pid == -1)
		return (ft_print_perror("fork"));
	else
	{
puts("wait2");
		pid = wait(&status);
puts("wait3");
		if (pid == -1)
			return (ft_print_perror("wait"));
		if (!(WIFEXITED(status)))
			return (ft_mes_error("Child process end with error."));
		return (0);
	}
	// return (ft_wait_judge_child(pid));
	return (0);
}

int final_exec(int *in_pipefd, char **argv)
{
	int	fdw;

	fdw = open("file2", O_WRONLY);
	if (fdw < 0)
		exit(ft_print_perror("file1"));
	if (close(in_pipefd[1]) == -1)
		exit(ft_print_perror("close"));
	if (dup2 (in_pipefd[0], STDIN_FILENO) == -1)
		exit(ft_print_perror("dup2"));
	if (dup2 (fdw, STDOUT_FILENO) == -1)
		exit(ft_print_perror("dup2"));
	if (close (fdw) == -1)
		exit(ft_print_perror("close"));
	if (execve("/bin/cat", argv, environ) == -1)
		exit(ft_print_perror("execve"));
	exit(EXIT_SUCCESS);
}

int main() {
    int in_pipefd[2];
    int out_pipefd[2];
    pid_t pid;
    char buffer[256];
	char *argv[] = {"/bin/cat", NULL};
	char *argv1[] = {"/usr/bin/wc", NULL};
	int repeat = 5;

    if (pipe(in_pipefd) == -1) 
		return (ft_print_perror("pipe"));
    pid = fork();
    if (pid == 0)
		first_exec(in_pipefd, argv);
	if (ft_wait_judge_child(pid) != 0)
		return (EXIT_FAILURE);
	while (repeat--)
	{
		if (pipe(out_pipefd) == -1) 
			return (ft_print_perror("pipe"));
puts("middle1");
		if (middle_exec(in_pipefd, out_pipefd, argv1) != 0)
			return (EXIT_FAILURE);
puts("middle2");
		in_pipefd[0] = out_pipefd[0];
		out_pipefd[1] = in_pipefd[1];
		if (close(in_pipefd[1]) == -1)
			return (ft_print_perror("close"));
	}
	pid = fork();
	if (pid == 0)
		final_exec(in_pipefd, argv);
	if (ft_wait_judge_child(pid) != 0)
		return (EXIT_FAILURE);
	close(in_pipefd[0]);
	close(in_pipefd[1]);
	close(out_pipefd[0]);
	close(out_pipefd[1]);
    return 0;
}
