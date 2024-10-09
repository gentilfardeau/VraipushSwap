#include "../../include/push_swap.h"

// Fonction de base de swap
bool	ft_swap(t_node **stack)
{
	t_node	*top;
	t_node	*bot;

	if (!*stack || !(*stack)->next)
		return (false);
	top = *stack;
	bot = (*stack)->next;
	*stack = bot;
	top->next = bot->next;
	bot->next = top;
	return (true);
}

// Swap A
bool	ft_swap_a(t_node **s_a, bool checker)
{
	if (!s_a || !ft_swap(s_a))
		return (false);
	if (checker)
		ft_printf("sa\n");
	return (true);
}

bool	ft_swap_b(t_node **s_b, bool checker)
{
	if (!s_b || !ft_swap(s_b))
		return (false);
	if (checker)
		ft_printf("sb\n");
	return (true);
}

bool	ft_swap_both(t_node **s_a, t_node **s_b, bool checker)
{
	if (!s_a || !s_b)
		return (false);
	if (!ft_swap(s_a) || !ft_swap(s_b))
		return (false);
	if (checker)
		ft_printf("ss\n");
	return (true);
}
