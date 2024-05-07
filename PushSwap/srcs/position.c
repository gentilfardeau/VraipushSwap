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

// Affecte la mediane
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
			stack->above_median = false;
		else
			stack->above_median = true;
		stack = stack->next;
		i++;
	}
	return (true);
}

bool ft_node_set(t_node *s_a, t_node *s_b)
{
	if (!s_a || !s_b)
		return (false);
	if (!ft_affect_current(s_b) || !ft_affect_median(s_b) 
		|| !ft_affect_current(s_a) || !ft_affect_median(s_a) 
		|| !ft_affect_cost(s_a, s_b)
		|| !ft_find_cheapest(s_b))
		return (false);
	return (true);
}
