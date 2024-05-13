#include "../include/push_swap.h"
// Trouve le target_node de chaque noeud
bool	ft_find_target_node(t_node *active, t_node *passive)
{
	int	i;
	t_node	*tmp;
	t_node	*target;

	if (!active || !passive)
		return (false);
	while (active)
	{
		i = INT_MAX;		
		tmp = active;
		while(tmp)
		{
			if (tmp->content > passive->content && tmp->content < i)
			{
				i = tmp->content;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (i == INT_MAX)
			active->target_node = ft_find_smallest(passive);
		else
			active->target_node = target;
		active = active->next;
	}
	return (true);
}
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
