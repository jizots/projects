typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list) * 1);
	if (newlist = NULL)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	value_return;

	if (lst == NULL)
		return (0);
	value_return = ft_lstsize(lst->next) + 1;
	if (value_return < 0)
		return (-1);
	return (value_return);
}
