#include "../../include/push_swap.h"

void ft_rotate(t_node **stack)
{
	t_node *last;
	t_node *newhead;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		if (!stack)
			return;
		last = ft_node_findlast(*stack);
		newhead = (*stack)->next;
		last->next = *stack;
		*stack = newhead;
		last->next->next = NULL;
	}
}

int ft_rotate_a(t_node **a)
{
	if (!a)
		return (1);
	ft_rotate(a);
	ft_printf("ra\n");
	return (0);
}

int ft_rotate_b(t_node **b)
{
	if (!b)
		return (1);
	ft_rotate(b);
	ft_printf("rb\n");
	return (0);
}

int ft_rotate_both(t_node **a, t_node **b)
{
	if (!a || !b)
		return (1);
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
	return (0);
}