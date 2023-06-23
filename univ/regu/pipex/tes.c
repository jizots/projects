#include "pipex.h"

extern char **environ;

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[256];
	int	fdr;
	int fdw;
	char *argv[] = {"/bin/cat", NULL};

	fdr = open("file1", O_RDONLY);
	fdw = open("file2", O_WRONLY);
    // パイプを作成
    if (pipe(pipefd) == -1) {
        fprintf(stderr, "パイプの作成に失敗しました\n");
        return 1;
    }
    // fork関数を呼び出して子プロセスを作成
    pid = fork();
    if (pid == 0)
	{
        // 子プロセスの処理
        close(pipefd[0]);
        dup2 (fdr, STDIN_FILENO);
		dup2 (pipefd[1], STDOUT_FILENO);
		execve("/bin/cat", argv, environ);
	}

	pid = fork();
	if (pid == 0)
	{
		dup2 (pipefd[0], STDIN_FILENO);
		dup2 (fdw, STDOUT_FILENO);
		execve("/bin/cat", argv, environ);
	}
	close (fdr);
	close (fdw);
    return 0;
}
