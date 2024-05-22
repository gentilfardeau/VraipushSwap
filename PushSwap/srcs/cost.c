#include "../include/push_swap.h"

// Update le cout pour les noeuds
bool	ft_set_cost(t_node *active, t_node *passive)
{
	int len_a;
	int len_p;

	if (!active || !passive)
		return (false);
	len_a = ft_stack_len(active);
	len_p = ft_stack_len(passive);
	while (active)
	{
		active->cost = active->current_pos;
		if (!(active->above_median))
			active->cost = len_a - (active->current_pos);
		if (active->target_node->above_median)
			active->cost += active->target_node->current_pos;
		else
			active->cost += len_p - (active->target_node->current_pos);
		active = active->next;
	}
	return (true);
}

// Compare les couts pour assigner le cheapest 
bool ft_set_cheapest(t_node *stack)
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

// Trouve le noeud avec cheapest = true 
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