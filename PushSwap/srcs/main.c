#include "../include/push_swap.h"

// Pense a secure les fonctions pour un seul element :D ///
int	main(int argc, char **argv)
{
	size_t	len;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || !argv[1])
		return (1);
	if (!ft_parsing(argv, &stack_a))
	{
		ft_free_all(stack_a, stack_b);
		return (ft_error_message());
	}
	len = ft_stack_len(stack_a);
	if (len == 2)
		ft_swap_a(&stack_a, true);
	else if (len == 3)
		ft_mini_sort(&stack_a);
	else if (len > 3)
		ft_sorting(&stack_a, &stack_b);
	else
	{
		ft_free_all(stack_a, stack_b);
		return (ft_error_message());
	}
	ft_free_all(stack_a, stack_b);
	return (0);
}
