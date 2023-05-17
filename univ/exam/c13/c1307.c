#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

int	get_data(void)
{
	static int	i = 0;

	return (i++);
}

t_btree	*ft_make_prefix(int n, int *array)
{
	t_btree	*newtree;
	int		nl, nr;

	if (n == 0)
		return (NULL);
	else
	{
		nl = n / 2;
		nr = n - nl - 1;
		newtree = btree_create_node(&array[get_data()]);
		if (newtree == NULL)
		{
			puts("malloc error");
			return (NULL);
		}
		newtree->left = ft_make_prefix(nl, array);
		newtree->right = ft_make_prefix(nr, array);
		return (newtree);
	}
}

void	print_tree(t_btree *t, int h)
{
	int	i;
	int	*a;

	if (t != NULL)
	{
		print_tree(t->right, h + 1);
		for (i = 0; i < h; i++)
			printf("\t");
		a = (int*)t->item;
		printf("%d\n", *a);
		print_tree(t->left, h + 1);
	}
}

void	free_tree(t_btree *root)
{
	if (root == NULL)
		return ;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

void	ft_putint(void *item, int current_level, int is_first_elem)
{
	int	*a = (int*)item;
	
	if (is_first_elem > 0)
		is_first_elem = 1;
	printf("item: %d, corrent_level: %d, first_elem?: %d\n", *a, current_level, is_first_elem);
}

t_queue	*create_queue(void)
{
	t_queue	*q;

	q = malloc(sizeof(t_queue));
	q->front = NULL;
	q->rear = NULL;
	return (q);
}

bool	is_empty(t_queue *q)
{
	return (q->front == NULL);
}

void	enqueue(t_queue	*q, t_btree *node)
{
	t_queue_node	*temp;
	
	temp = malloc(sizeof(t_queue_node));
	temp->node = node;
	temp->next = NULL;
	if (q->rear == NULL)
	{
		q->front = temp;
		q->rear = temp;
		return ;
	}
	q->rear->next = temp;
	q->rear = temp;
}

t_btree	*dequeue(t_queue *q)
{
	if (is_empty(q))
		return NULL;
	t_queue_node	*temp;
	t_btree			*node;

	temp = q->front;
	node = temp->node;
	q->front =temp->next;
	if (q->front == NULL)
		q->rear = NULL;
	free (temp);
	return (node);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
    if (root == NULL)
		return ;
	
	t_queue	*queue;

	queue = create_queue();
	enqueue(queue, root);
	
	int	depth;
	depth = 0;

	while (!is_empty(queue))
	{
		int	node_count;
		t_queue_node *tmp;

		node_count = 0;
		tmp = queue->front;
		while (tmp != NULL)
		{
			node_count++;
			tmp = tmp->next;
		}
		while (node_count > 0)
		{
			t_btree	*node;

			node = dequeue(queue);
// puts("befor applyf");
			applyf(node->item, depth, depth);
// puts("after applyf");
			if (node->left)
				enqueue(queue, node->left);
			if (node->right)
				enqueue(queue, node->right);
			node_count--;
		}
		depth++;
	}
}

int	main(void)
{
	t_btree	*root;
	int		array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	int		count_array = sizeof(array) / sizeof(int);

	root = ft_make_prefix(count_array, array);
	print_tree(root, 0);
	btree_apply_by_level(root, ft_putint);
	free_tree(root);

	return (0);
}