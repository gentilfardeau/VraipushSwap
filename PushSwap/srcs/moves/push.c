#include "../../include/push_swap.h"

// Push d'une stack a l'autre
void ft_push(t_node **src, t_node **dst)
{
	t_node *tmp;

	if (!dst || !src)	
		return;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	return;
}

// Push de B vers A
void ft_push_a(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_write("pa\n");
	return;
}

// Push de A vers B
void ft_push_b(t_node **stack_a, t_node **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_write("pb\n");
	return;
}
