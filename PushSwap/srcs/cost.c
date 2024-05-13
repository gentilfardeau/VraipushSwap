#include "../include/push_swap.h"

// Update le cout
bool	ft_affect_cost(t_node *active, t_node *passive)
{
	int len_b;

	if (!active || !passive)
		return (false);
	len_b = ft_stack_len(passive);
	if (!ft_affect_current(passive) || !ft_affect_current(active))
		return (false);
	while (passive)
	{
		if (passive->above_median == true)
			passive->cost = passive->current_pos + passive->target_node->current_pos; 
		else
			passive->cost = len_b - passive->current_pos + passive->target_node->current_pos;
		ft_printf("Noeud traite = %d || Cout = %d \n", passive->content, passive->cost);
		passive = passive->next;
	}
	return (true);
}

// Trouve le cout le plus petit pour bouger le prochain noeud
bool ft_affect_cheapest(t_node *stack)
{
	int min;
	t_node *tmp;

	if (!stack)
		return (false);
	tmp = stack;
	min = stack->cost;
	while (tmp)
	{
		if (tmp->cost < min)	
			min = tmp->cost;
		tmp = tmp->next;
	}
	while (stack)
	{
		if (stack->cost == min)
		{
			stack->cheapest = true;
			return (true);
		}
		stack = stack->next;
	}
	return (false);
}

t_node *ft_find_cheapest(t_node *stack)
{
	while (stack)
	{
		if (stack->cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}