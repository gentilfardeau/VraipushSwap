#include "../include/push_swap.h"

// Renvoie true si la stack est triee
bool ft_stack_sorted(t_node *stack)
{
	int max;

	while(stack->next != NULL)
	{
		max = stack->content;
		stack = stack->next;
		if (stack->content < max)
			return (false);
	}
	return (true);
}

// Finalise le tri pour mettre le plus petit en premier
bool ft_final_sort(t_node **s_a)
{
	if (!s_a)
		return (false);
	while ((*s_a)->content != ft_find_smallest(*s_a)->content)
	{
		if (ft_find_smallest(*s_a)->above_median)
			ft_ra(s_a, false);
		else
			ft_rra(s_a , false);
	}
	return (true);
}