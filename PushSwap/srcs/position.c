#include "../include/push_swap.h"

// Affecte current_pos a la stack
bool ft_affect_current(t_node *stack)
{
	int i;

	if (!stack)
		return (false);
	i = 0;
	while(stack)
	{
		stack->current_pos = i;
		stack = stack->next;
		i++;
	}
	return (true);
}

bool ft_affect_median(t_node *stack)
{
	int i;
	int len;

	if (!stack)
		return (false);
	i = 0;
	len = ft_stack_len(stack);
	while (stack)
	{
		if (i > len / 2)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
	return (true);
}

