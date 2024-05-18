#include "../include/push_swap.h"


bool ft_final_sort(t_node **s_a)
{
	t_node *min;

	if (!s_a)
		return (false);
	min = ft_find_smallest(*s_a);
	while ((*s_a)->content != min->content)
	{
		if (min->above_median)
			ft_ra(s_a, false);
		else
			ft_rra(s_a , false);
	}
	return (true);
}