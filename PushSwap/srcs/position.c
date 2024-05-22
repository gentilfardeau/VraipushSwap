#include "../include/push_swap.h"

// Trouve les target_node pour A
bool	ft_set_target_a(t_node *s_a, t_node *s_b)
{
	t_node *current_b;
	t_node *target;
	int match_index;

	if (!s_a || !s_b)
		return (false);
	while (s_a)
	{
		match_index = INT_MIN;
		current_b = s_b;
		while (current_b)
		{
			if (current_b->content < s_a->content && current_b->content > match_index)
			{
				match_index = current_b->content;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (match_index == INT_MIN)
			s_a->target_node = ft_find_biggest(s_b);
		else
			s_a->target_node = target;
		s_a = s_a->next;
	}
	return (true);
}

// Trouve les target_node pour B
bool ft_set_target_b(t_node *s_a, t_node *s_b)
{
	t_node *current_a;
	t_node *target;
	long match_index;

	if (!s_a || !s_b)
		return (false);
	while (s_b)
	{
		match_index = 2147483648;
		current_a = s_a;
		while (current_a)
		{
			if (current_a->content > s_b->content && current_a->content < match_index)
			{
				match_index = current_a->content;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (match_index == 2147483648)
			s_b->target_node = ft_find_smallest(s_a);
		else
			s_b->target_node = target;
		s_b = s_b->next;
	}
	return (true);
}

// Set current_pos a la stack
bool ft_set_current(t_node *stack)
{
	int i;
	int median;

	if (!stack)
		return (false);
	i = 0;
	median = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->current_pos = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
	return (true);
}
