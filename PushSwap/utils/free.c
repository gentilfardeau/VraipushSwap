#include "../include/push_swap.h"

// Libere un noeud
int ft_free_node(t_node *node)
{
	if (!node)
		return (1);
	free(node);
	return (0);
}

// Libere les stacks A et B
int ft_free_all(t_node *s_a, t_node *s_b)
{
	t_node *tmp;
	while(s_a)	
	{
		tmp = s_a->next;
		if(ft_free_node(s_a))
			return (1);
		s_a = tmp;
	}
	while(s_b)	
	{
		tmp = s_b->next;
		if (ft_free_node(s_b))
			return (1);
		s_b = tmp;
	}
	return (0);
}
