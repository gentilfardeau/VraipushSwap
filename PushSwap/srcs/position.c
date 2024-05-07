#include "../include/push_swap.h"

// Affecte current_pos a la stack
int ft_current_affect(t_node *stack)
{
	int i;

	i = 0;
	if (!stack)
		return (1);
	while (stack)
	{
		stack->current_pos = i;	
		stack = stack->next;
		i++;
	}
	return (0);
}