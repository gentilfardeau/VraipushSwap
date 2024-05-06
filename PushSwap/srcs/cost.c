#include "../include/push_swap.h"

t_node *ft_find_target_node(t_node *node, t_node *s_a)
{
}

int ft_cost_affect(t_node *s_b, t_node *s_a)
{
}

int ft_cost_node(t_node **stack_a)
{
	t_node *tmp;
 
	tmp = *stack_a;
	if (!stack_a)
		return (1);
	while (stack_a != NULL)
	{
		(*stack_a)->cost = ft_cost_affect(*stack_a, tmp);
		*stack_a = (*stack_a)->next;
	}
	return (0);
}