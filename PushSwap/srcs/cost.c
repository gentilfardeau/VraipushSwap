#include "../include/push_swap.h"

// Assigne a chaque noeud sa target
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
	return (true);
}

// Update le cout
bool ft_affect_cost(t_node *s_a, t_node *s_b)
{
	int len_b;

	if (!s_a || !s_b)
		return (false);
	len_b = ft_stack_len(s_b);
	if (!ft_affect_current(s_b) || !ft_affect_current(s_a))
		return (false);
	while (s_b)
	{
		ft_printf("Noeud traite = %d || Cout = %d || Current : %d\n", s_b->content, s_b->target_node->content, s_b->current_pos);
		ft_printf("Noeud target = %d || Pos = %d\n", s_b->target_node->content, s_b->target_node->current_pos);
		if (s_b->above_median == true)
			s_b->cost = s_b->current_pos + s_b->target_node->current_pos; 
		else
			s_b->cost = len_b - s_b->current_pos + s_b->target_node->current_pos;
		ft_printf("Noeud traite = %d || Cout = %d \n", s_b->content, s_b->cost);
		s_b = s_b->next;
	}
	return (true);
}

// Trouve le cout le plus petit pour bouger le prochain noeud
bool ft_find_cheapest(t_node *s_b)
{
	int min;
	t_node *tmp;

	if (!s_b)
		return (false);
	tmp = s_b;
	min = s_b->cost;
	while (tmp)
	{
		if (tmp->cost < min)	
			min = tmp->cost;
		tmp = tmp->next;
	}
	while (s_b)
	{
		if (s_b->cost == min)
		{
			s_b->cheapest = true;
			return (true);
		}
		s_b = s_b->next;
	}
	return (false);
}