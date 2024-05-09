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
	if (!ft_sorting(&stack_a, &stack_b))
		ft_printf(" JAJAJA\n");
	ft_print_stack_content(stack_a, "target_node");
	ft_printf("Puteuh \n");
	ft_free_all(stack_a, stack_b);
	return (0);
}

// int main (int argc, char **argv)
// {
// 	size_t len;
// 	t_node *stack_a = NULL;
// 	t_node *stack_b = NULL;

// 	if (argc < 2 || !argv[1])
// 		return (ft_error_message());
// 	if (!ft_parsing(argv, &stack_a))
// 		return (ft_error_message());
// 	if (!ft_stack_sorted(stack_a))
// 	{
// 		len = ft_stack_len(stack_a);
// 		if (len == 2)
// 			ft_swap_a(&stack_a, false);
// 		if (len == 3)
// 			ft_mini_sort(&stack_a);
// 		if (len > 3)
// 			ft_sorting(&stack_a, &stack_b);
// 	}
// 	else
// 	{
// 		ft_free_all(stack_a, stack_b);
// 		return (ft_error_message());
// 	}
// 	ft_print_stack_content(stack_a, "content");
// 	ft_free_all(stack_a, stack_b);
// 	return (0);
// }