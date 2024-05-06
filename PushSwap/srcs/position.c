#include "../include/push_swap.h"

// Affecte a chaque noeud sa target_pos
int ft_target_affect(t_node *stack, t_node *node)
{
	int i;

	i = 0;
	while(stack)
	{
		if (node->content > stack->content)
			i++;
		stack = stack->next;
	}
	return (i);
}

// Affecte target_pos a tous les noeuds
int ft_target_init(t_node *stack)
{
	t_node *tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp)
	{
		tmp->target_pos = ft_target_affect(stack, tmp);
		tmp = tmp->next;
	}
	return(0);
}

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