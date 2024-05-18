#include "../../include/push_swap.h"

// Fonction de base reverse_rotate
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

// Reverse rotate a 
bool ft_rra(t_node **s_a, bool checker)
{
	if (!s_a)
		return (false);
	if (!ft_reverse_rotate(s_a))
		return (false);
	if (checker)
		ft_printf("rra\n");
	return (true);
}

 // Reverse rotate b
bool ft_rrb(t_node **s_b, bool checker)
{
	if (!s_b)
		return (false);
	ft_reverse_rotate(s_b);
	if (checker)
		ft_printf("rrb\n");
	return (true);
}

bool	ft_rrr(t_node **s_a, t_node **s_b, bool checker)
{
	if (!s_a || !s_b)
		return (false);
	if (!ft_rra(s_a, false) || !ft_rrb(s_b, false))
		return (false);
	if (checker)
		ft_printf("rrr\n");
	return (true);
}
// Reverse rotate les 2
bool ft_rev_rotate_both(t_node **s_a, t_node **s_b, t_node *cheap)
{
	if (!s_a || !s_b || !cheap)
		return (false);
	while (*s_b != cheap->target_node && *s_a != cheap)
		ft_rrr(s_a, s_b, false);
	ft_set_current(*s_a);
	ft_set_current(*s_b);
	return (true);
}