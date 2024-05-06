#include "../include/push_swap.h"

	// Pense a secure les fonctions pour un seul element :D ///

int main(int argc, char **argv)
{
	t_node *stack_a = NULL;
	t_node *stack_b = NULL;

	if (argc <= 1)
		return (0);
	if (ft_parsing(argv, &stack_a) || ft_stack_sorted(stack_a))
	{
		ft_free_all(stack_a, stack_b);
		return (ft_error_message());
	}
	while(ft_stack_len(stack_a) > 3)
		ft_push_b(&stack_a, &stack_b);
	// while (stack_b)
	// {
	// 	ft_cost_affect(stack_b, stack_a);
	// 	stack_b = stack_b->next;
	// }
	ft_print_stack_content(stack_b, "content");
	ft_print_stack_content(stack_a, "content");
	ft_cost_affect(stack_b, stack_a);
	ft_print_stack_content(stack_b, "target_node");
	// ft_cost_affect(stack_b, stack_a);
	if (ft_sorting(stack_a, stack_b))
		return (ft_free_all(stack_a, stack_b));
	// ft_free_all(stack_a, stack_b);
	return (0);
}

/*
int main (int argc, char **argv)
{
	size_t len;
	t_node *stack_a = NULL;
	t_node *stack_b = NULL;

	if (argc < 2 || !argv[1])
		return (ft_error_message());
	if (!ft_parsing(argc, argv))
		return (ft_error_message());
	if (!ft_stack_sorted(stack_a))
	{
		stack_len = ft_stack_len(stack_a);
		if (stack_len == 2)
			ft_sa(stack_a);
		if (stack_len == 3)
			ft_sort_three(stack_a);
		if (stack_len > 3)
			ft_real_sort(stack_a, stack_b);
	}
	else
	{
		ft_free_stacks(stack_a, stack_b);
		return (ft_error_message());
	}
	ft_free_stacks(stack_a, stack_b);
	return (0);
}*/