#include "../include/push_swap.h"

// Renvoie 1 si la stack est triee
int ft_stack_sorted(t_node *stack)
{
	int max;

	while(stack->next != NULL)
	{
		max = stack->content;
		stack = stack->next;
		if (stack->content < max)
			return (0);
	}
	return (1);
}

// Permet les deplacements de A vers B
bool ft_move_a_to_b(t_node **s_a, t_node **s_b)
{
	t_node *cheap;

	cheap = ft_find_cheapest(*s_a);
	if (cheap->above_median && cheap->target_node->above_median)
		ft_rotate_both(s_a, s_b, cheap);
	else if (!(cheap->above_median) && !(cheap->target_node->above_median))
		ft_rev_rotate_both(s_a, s_b, cheap);
	ft_set_to_push(s_a, cheap, 'a');
	ft_set_to_push(s_b, cheap->target_node, 'b');
	ft_push_b(s_a, s_b, false);
	return (true);
}

// Permet les deplacements de B vers A
bool ft_move_b_to_a(t_node **s_a, t_node **s_b)
{
	if (!s_a || !s_b)
		return (false);
	ft_set_to_push(s_a, (*s_b)->target_node, 'a');
	ft_push_a(s_a, s_b, false);
	return (true);
}

bool ft_mini_sort(t_node **s_a)
{
	t_node *max;

	if (!s_a)
		return (false);
	max = ft_find_biggest(*s_a);
	if (max == (*s_a))
		ft_ra(s_a, false);
	else if ((*s_a)->next == max)
		ft_rra(s_a, false);
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
	ft_printf("Avant SB\n");
	ft_print_stack_content(*s_a, "content", 'a');
	while (*s_b)
	{
		if (!ft_set_nodes_b(*s_a, *s_b))
			ft_printf("Zgueugounet\n");
		ft_printf("Uiiii\n");
		if (!ft_move_b_to_a(s_a, s_b))
			ft_printf("Zeub\n");
	}
	ft_set_current(*s_a);
	ft_print_stack_content(*s_a, "current_pos", 'a');
	ft_final_sort(s_a);
	return (true);
}