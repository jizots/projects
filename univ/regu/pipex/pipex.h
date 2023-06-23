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
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);

//prototype
char	**ft_search_envpaths(void);
char	*ft_get_absolute_path(char **paths, char *command);//access
int		ft_exec_command(char *ab_path, char **option, char *insorce);//execve, open, read, write, pipe
int		ft_print_perror(char *original_message);//perror, write
int		ft_mes_error(char *message);
int		ft_free_matrix(char **matrix, int flag_error);

#endif