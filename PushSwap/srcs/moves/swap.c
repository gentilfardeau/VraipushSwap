#include "../../include/push_swap.h"

// Fonction de base de swap
int ft_swap(t_node **stack)
{
	t_node *top;
	t_node *bot;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		top = *stack;
		bot = (*stack)->next;
		*stack = bot;
		top->next = bot->next;
		bot->next = top;
	}
	return (0);
}

// Swap A
int ft_swap_a(t_node **a)
{
	ft_swap(a);
	ft_printf("sa\n");
	return (0);
}

// Swap B
int ft_swap_b(t_node **b)
{
	ft_swap(b);
	ft_printf("sb\n");
	return (0);
}

// Swap les deux stacks
int ft_swap_both(t_node **a, t_node **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
	return (0);
}