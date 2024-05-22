#include "../include/push_swap.h"

// Cree et ajoute le noeud a la fin de la stack
bool	ft_node_addback(int content, t_node **stack)
{
	t_node	*tmp;
	t_node	*new;


	if (!content || !stack)
		return (false);
	new = ft_node_init(content);
	if (new)
	{
		if (*stack == NULL)
			*stack = new;
		else 
		{
			tmp = ft_find_last(*stack);
			tmp->next = new;
			new->previous = tmp;	
		}
	}
	else
		return (false);
	return (true);
}

// Operations pour set les caracs de s_a
bool	ft_set_nodes_a(t_node *s_a, t_node *s_b)
{
	if (!s_a)
		return (false);
	ft_set_current(s_a);
	ft_set_current(s_b);
	ft_set_target_a(s_a, s_b);
	ft_set_cost(s_a, s_b);
	ft_set_cheapest(s_a);
	return (true);
}



// Operations pour set les caracs de s_b
bool ft_set_nodes_b(t_node *s_a, t_node *s_b)
{
	if (!s_a || !s_b)
		return (false);
	ft_set_current(s_a);
	ft_set_current(s_b);
	ft_set_target_b(s_a, s_b);
	return (true);
}
 
// Prepare pour transferer vers l'autre stack
bool ft_set_to_push(t_node **stack, t_node *top, char c)
{
	while (*stack != top)
	{
		if (c == 'a')
		{
			if (top->above_median)
				ft_ra(stack, true);
			else
				ft_rra(stack, true);
		}
		else if (c == 'b')
		{
			if (top->above_median)
				ft_rb(stack, true);
			else
				ft_rrb(stack, true);
		}
	}
	return (true);
}