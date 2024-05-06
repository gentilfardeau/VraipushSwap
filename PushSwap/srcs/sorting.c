#include "../include/push_swap.h"

// Gere la gestion des mouvements
// int ft_operate(t_node **stack_a, t_node **stack_b)
//{
// return (1);
//}

// Synthetise et assemble le tri, et renvoie le nombre de moves
// Prend en compte : l'affectations du poids, de l'index final et des mouvements

int ft_huge_sort(t_node *s_a, t_node *s_b)
{
	ft_printf("HUUUUUGE \n");
	ft_print_stack_content(s_a, "content");
	ft_print_stack_content(s_b, "content");
	return (0);
}
int ft_tiny_sort(t_node *s_a, t_node *s_b)
{
	ft_printf("tiny \n");
	ft_print_stack_content(s_a, "content");
	ft_print_stack_content(s_b, "content");
	return (0);
}

int ft_mini_sort(t_node *s_a)
{
	ft_printf("mini \n");
	ft_print_stack_content(s_a, "next");
	return (0);
}

int ft_sorting(t_node *stack_a, t_node *stack_b)
{
	if (ft_target_init(stack_a) || ft_current_affect(stack_a))
		return (1);
	if (ft_stack_len(stack_a) == 3)
		ft_mini_sort(stack_a);
	else if (ft_stack_len(stack_a) <= 5)
		ft_tiny_sort(stack_a, stack_b);
	else if (ft_stack_len(stack_a) > 5)
		ft_huge_sort(stack_a, stack_b);
	return (0);
}