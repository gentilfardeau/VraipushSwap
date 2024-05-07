#include "../include/push_swap.h"

// Affecte a chaque noeud sa target_pos
t_node *ft_target_affect(t_node *stack, t_node *node)
{
	t_node *min_max;

	min_max = stack;
	ft_printf("Min_max : %d \n", min_max->content);
	ft_printf("Min_max content: %d \n", stack->content);
	while(stack)
	{
		
		if (min_max->content > stack->content && stack->content > node->content)
			min_max = stack;
		stack = stack->next;
	}
	ft_printf("Min_max de fin : %d \n", min_max->content);
	return (min_max);
}

// Affecte target_pos a tous les noeuds
int ft_target_init(t_node *s_a, t_node *s_b)
{
	t_node *tmp;

	if (!s_b)
		return (1);
	tmp = s_b;
	while (tmp)
	{
		tmp->target_node = ft_target_affect(s_a, tmp);
		tmp = tmp->next;
	}
	return(0);
}
