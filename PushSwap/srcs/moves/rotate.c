#include "../../include/push_swap.h"

// Fonction de base de rotate
bool ft_rotate(t_node **stack)
{
	t_node *last;
	t_node *newhead;

	if (!*stack || !(*stack)->next)
		return (false);
	last = ft_find_last(*stack);
	newhead = (*stack)->next;
	last->next = *stack;
	*stack = newhead;
	last->next->next = NULL;
	return (true);
}

// Rotate A
bool ft_ra(t_node **s_a, bool checker)
{
	if (!s_a)
		return (false);
	if (!ft_rotate(s_a))
		return (false);
	if (checker)
		ft_printf("ra\n");
	return (true);
}

// Rotate B
bool ft_rb(t_node **s_b, bool checker)
{
	if (!s_b || !ft_rotate(s_b))
		return (false);
	if (checker)
		ft_printf("rb\n");
	return (true);
}

// Rotate A et B
bool ft_rr(t_node **s_a, t_node **s_b, bool checker)
{
	if (!s_a || !s_b)
		return (false);
	if (!ft_ra(s_a, false) || !ft_rb(s_b, false))
		return (false);
	if (checker)
		ft_printf("rr\n");
	return (true);
}

// RR tant que cheapest ou target_node ne sont pas au top
bool ft_rotate_both(t_node **s_a, t_node **s_b, t_node *cheap)
{
	if (!s_a || !s_b || !cheap)
		return (false);
	while (*s_b != cheap->target_node && *s_a != cheap)
		ft_rr(s_a, s_b, true);
	ft_set_current(*s_a);
	ft_set_current(*s_b);
	return (true);
}
 