#include "../include/push_swap.h"

// Gere la gestion des mouvements

// Synthetise et assemble le tri, et renvoie le nombre de moves
// Prend en compte : l'affectations du poids, de l'index final et des mouvements

bool ft_set_to_push(t_node **stack, t_node *on_top, char c)
{
	while ((*stack)->content != on_top->content)
	{
		if (c == 'a')
		{
			ft_print_stack_content(*stack, "cheapest", 'a');
			if (on_top->above_median)
				ft_rotate_a(stack, false);
			else
				ft_reverse_rotate_a(stack, false);
			
		}
		else if (c == 'b')
		{
			if (on_top->above_median)
				ft_rotate_b(stack, false);
			else
				ft_reverse_rotate_b(stack, false);
		}
		else
			return (false);
	}
	return (true);
}

bool ft_move_a_to_b(t_node **s_a, t_node **s_b)
{
	t_node *cheap;

	if (!s_a || !s_b)
		return (false);
	cheap = ft_find_cheapest(*s_a);
	if (cheap->above_median && cheap->target_node->above_median)
		ft_rotate_both(s_a, s_b, false);
	else if (!cheap->above_median && !cheap->target_node->above_median)
		ft_complete_rotate(s_a, s_b, cheap);
	if (!ft_set_to_push(s_a, cheap, 'a') || !ft_set_to_push(s_b, cheap->target_node,'b'))
		return (false);
	ft_push_b(s_a, s_b, false);
	return (true);
}

bool ft_move_b_to_a(t_node **s_a, t_node **s_b)
{
	if (!s_a || !s_b)
		return (false);
	if (!ft_set_to_push(s_a,(*s_b)->target_node, 'a'))
		return (false);
	if (!ft_push_a(s_a, s_b, false))
		return (false);
	return (true);
}

bool ft_min_to_top(t_node **s_a)
{
	t_node *smallest;

	smallest = ft_find_smallest(*s_a);
	if (!smallest || !s_a)
		return (false);
	while ((*s_a)->content != smallest->content)
	{
		if (smallest->above_median)
			ft_rotate_a(s_a, false);
		else
			ft_reverse_rotate_a(s_a, false);
	}
	return (true);
}

bool ft_mini_sort(t_node **s_a)
{
	t_node *max;

	if (!s_a)
		return (false);
	max = ft_find_biggest(*s_a);
	if (max == (*s_a))
		ft_rotate_a(s_a, false);
	else if ((*s_a)->next == max)
		ft_reverse_rotate_a(s_a, false);
	if ((*s_a)->content > (*s_a)->next->content)
		ft_swap_a(s_a, false);
	return (true);
}

bool ft_sorting(t_node **s_a, t_node **s_b)
{
	int len_a;

	if (!s_a || !s_b)
		return (false);
	len_a = ft_stack_len(*s_a);
	if (len_a-- > 3 && !ft_stack_sorted(*s_a))
		ft_push_b(s_a, s_b, false);
	if (len_a-- > 3 && !ft_stack_sorted(*s_a))
		ft_push_b(s_a, s_b, false);
	while (len_a-- > 3 && !ft_stack_sorted(*s_a))
	{
		if (!ft_set_nodes_a(*s_a, *s_b) || !ft_move_a_to_b(s_a, s_b))
			return (false);
	}
	ft_mini_sort(s_a);
	while (*s_b)
	{
		if (!ft_set_nodes_b(*s_b, *s_a) || !ft_move_b_to_a(s_a, s_b))
			return (false);
	}
	ft_affect_current(*s_a);
	ft_final_sort(s_a);
	return (true);
}