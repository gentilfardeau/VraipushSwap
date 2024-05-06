#include "../../include/push_swap.h"

void ft_reverse_rotate(t_node **stack)
{

	t_node *last;
	t_node *before_last = NULL;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		while (last->next != NULL)
		{
			before_last = last;
			last = last->next;
		}
		before_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

// Reverse rotate a uniquement

int ft_rr_a(t_node **a)
{
	ft_reverse_rotate(a);
	ft_printf("rra\n");
	return (0);
}

int ft_rr_b(t_node **b)
{
	ft_reverse_rotate(b);
	ft_printf("rrb\n");
	return (0);
}

int ft_rrr(t_node **a, t_node **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf("rrr\n");
	return (0);
}

/*
void ft_reverse_rotate(t_node **stack)
{
	t_node *last;

	last = ft_node_findlast(&stack);

}*/