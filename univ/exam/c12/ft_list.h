#include <stdlib.h>
#include <stdio.h>

typedef struct	s_list
{
	struct	s_list	*next;
	void			*data;
}	t_list;

t_list	*ft_create_elem(void *data);
t_list	*ft_list_push_strs(int size, char **strs);