#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
} t_btree;

typedef struct s_queue_node
{
	t_btree				*node;
	struct s_queue_node	*next;
	
}	t_queue_node;

typedef struct s_queue
{
	t_queue_node	*front;
	t_queue_node	*rear;
}	t_queue;

t_btree	*btree_create_node(void *item);