#include "push_swap.h"

static t_list	*ft_fail_value(t_list *root, int *p_value)
{
	free(p_value);
	if (root != NULL)
		ft_delete_datas(root);
	return (NULL);
}

t_list	*ft_make_initial_stack(char **args, t_list *root)
{
	int		i;
	int		*p_value;
	char	*flag_error;

	i = 0;
	root = NULL;
	while (args[i] != NULL)
	{
		p_value = malloc (sizeof(int) * 1);
		if (p_value == NULL)
		{
			ft_delete_datas(root);
			return (NULL);
		}
		flag_error = args[i];
		*p_value = ft_atoi(args[i++], &flag_error);
		if (flag_error == NULL)
			return (ft_fail_value(root, p_value));
		root = ft_add_stack(root, p_value);
	}
	return (root);
}