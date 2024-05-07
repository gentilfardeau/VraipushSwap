#include "../include/push_swap.h"

bool ft_find_target_node(t_node *s_a, t_node *s_b)
{
	int	i;
	t_node	*tmp;
	t_node	*target;

	if (!s_a || !s_b)
		return (false);
	while (s_b)
	{
		i = INT_MAX;		
		tmp = s_a;
		while(tmp)
		{
			if (tmp->content > s_b->content && tmp->content < i)
			{
				i = tmp->content;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (i == INT_MAX)
			s_b->target_node = ft_find_smallest(s_a);
		else
			s_b->target_node = target;
		s_b = s_b->next;
	}
	return (true):
}

bool ft_affect_cost(t_node *s_a, t_node *s_b)
{
	if (!stack)
		return (false);
	ft_find_target_node(s_a, s_b);
	while (stack)
	{
		stack = stack->next;
	}
	return (true);
}