#ifndef PIPEX_H
# define PIPEX_H

//define

//include
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include <stddef.h>
# include <fcntl.h>

//prototype libft
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);

//prototype
int		ft_wait_judge_child(int pid);
char	**ft_search_envpaths(char ***matrix_path);
int		ft_get_absolute_path(char **matrix_path, char *command, char **full_path);
int		ft_fork_for_infile(int *in_pipefd, char **matrix_cmd);
int		ft_fork_for_repeat_pipe(int *out_pipefd, int *in_pipefd, char **argv1, int ac);
int		ft_fork_for_outfile(int *in_pipefd, char **argv, int ac);
int		ft_print_perror(char *original_message);
int		ft_mes_error(char *message);
int		ft_free_allocates(char **matrix1, char **matrix2, char *s, int flag_error);

//test only
void	printmatrix(char **matrix, char *name_item);

#endif