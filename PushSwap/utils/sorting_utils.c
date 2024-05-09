#include "../include/push_swap.h"

bool ft_move_sort(t_node *active, t_node *passive)
{
	if (!active || !passive)
		return (false);
	return (true);
}

bool ft_final_sort(t_node *s_a)
{
	if (!s_a)
		return (false);
	while (!ft_stack_sorted(s_a))
	{
		if (ft_find_smallest(s_a)->above_median)
			ft_rotate_a(&s_a, false);
		else
			ft_rr_a(&s_a, false);
	}
	return (true);
}