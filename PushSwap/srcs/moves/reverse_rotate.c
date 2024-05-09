#include "../../include/push_swap.h"

bool ft_reverse_rotate(t_node **stack)
{

	t_node *last;
	t_node *before_last = NULL;

	if (!(*stack != NULL && (*stack)->next != NULL))
		return (false);

	last = *stack;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (true);
}

// Reverse rotate a uniquement

bool ft_rr_a(t_node **s_a, bool checker)
{
	if (!s_a)
		return (false);
	ft_reverse_rotate(s_a);
	if (checker)
		ft_printf("rra\n");
	return (true);
}

bool ft_rr_b(t_node **s_b, bool checker)
{
	if (!s_b)
		return (false);
	ft_reverse_rotate(s_b);
	if (checker)
		ft_printf("rrb\n");
	return (true);
}

bool ft_rrr(t_node **s_a, t_node **s_b, bool checker)
{
	if (!s_a || !s_b)
		return (false);
	ft_reverse_rotate(s_a);
	ft_reverse_rotate(s_b);
	if (checker)
		ft_printf("rrr\n");
	return (true);
}