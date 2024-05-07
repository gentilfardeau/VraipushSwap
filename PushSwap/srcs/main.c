#include "../include/push_swap.h"

	// Pense a secure les fonctions pour un seul element :D ///

int main(int argc, char **argv)
{
	t_node *stack_a = NULL;
	t_node *stack_b = NULL;

	if (argc <= 1)
		return (0);
	if (!ft_parsing(argv, &stack_a) || ft_stack_sorted(stack_a))
	{
		ft_free_all(stack_a, stack_b);
		return (ft_error_message());
	}
	while(ft_stack_len(stack_a) > 3)
		ft_push_b(&stack_a, &stack_b);
	ft_find_target_node(stack_a, stack_b);
	ft_affect_median(stack_a);
	ft_affect_median(stack_b);
	ft_node_set(stack_a, stack_b);
	ft_print_stack_content(stack_b, "target_node");
	ft_print_stack_content(stack_b, "above_median");
	ft_print_stack_content(stack_a, "current_pos");
	ft_print_stack_content(stack_b, "cost");
	ft_free_all(stack_a, stack_b);
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