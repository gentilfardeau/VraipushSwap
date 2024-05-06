#include "../include/push_swap.h"

// Renvoie 1 si la stack est triee
int ft_stack_sorted(t_node *stack)
{
	int max;

	while(stack->next != NULL)
	{
		max = stack->content;
		stack = stack->next;
		if (stack->content < max)
			return (0);
	}
	return (1);
}