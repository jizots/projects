/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:50:51 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/29 19:24:55 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//include
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include <stddef.h>
# include <fcntl.h>

//deffine
# define PIPE 1
# define SEMIC 2
# define OREDIR 3
# define OOREDIR 4
# define IREDIR 5
# define HREDIR 6

//typedef
typedef struct s_cmds
{
	int				ac;
	char			**av;
	char			**matrix_env;
	char			**matrix_epath;
	int				delim;
	char			**matrix_cmd;
	char			*path_cmd;
	int				in_pipefd[2];
	int				out_pipefd[2];
	struct s_cmds	*next;
}	t_cmds;

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
int		ft_init_data(t_cmds *data, int ac, char *av[], char *envp[]);
int		ft_wait_judge_child(int pid);
char	**ft_search_envpaths(char ***matrix_path);
int		ft_get_absolute_path(t_cmds *data);
int		ft_fork_for_infile(t_cmds *data);
int		ft_fork_for_repeat_pipe(t_cmds *data);
int		ft_fork_for_outfile(t_cmds *data);
int		ft_print_perror(char *original_message);
int		ft_mes_error(char *message);
int		ft_free_allocates(char **matrix1,
			char **matrix2, char *s, int flag_error);

//test only
// void	printmatrix(char **matrix, char *name_item);

#endif