#include "../../include/push_swap.h"

bool ft_rotate(t_node **stack)
{
	t_node *last;
	t_node *newhead;

	if (!*stack || !(*stack)->next)
		return (false);
	last = ft_node_findlast(*stack);
	newhead = (*stack)->next;
	last->next = *stack;
	*stack = newhead;
	last->next->next = NULL;
	return (true);
}

bool ft_rotate_a(t_node **s_a, bool checker)
{
	if (!s_a)
		return (false);
	if (!ft_rotate(s_a))
		ft_printf("Suce\n");
	if (checker)
		ft_printf("ra\n");
	return (true);
}

bool ft_rotate_b(t_node **s_b, bool checker)
{
	if (!s_b || !ft_rotate(s_b))
		return (false);
	if (checker)
		ft_printf("rb\n");
	return (true);
}

bool ft_rotate_both(t_node **s_a, t_node **s_b, bool checker)
{
	if (!s_a || !s_b)
		return (false);
	if (!ft_rotate(s_a) || !ft_rotate(s_b))
		return (false);
	if (checker)
		ft_printf("rr\n");
	return (true);
}
 
bool ft_complete_rotate(t_node **s_a, t_node **s_b, t_node *cheap)
{
	while(*s_b != cheap->target_node && *s_a != cheap)
		ft_rotate_both(s_a, s_b, false);
	ft_affect_current(*s_a);
	ft_affect_current(*s_b);
	return (true);
}