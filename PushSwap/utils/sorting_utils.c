#include "../include/push_swap.h"


bool ft_final_sort(t_node **s_a)
{
	if (!s_a)
		return (false);
	while ((*s_a)->content != ft_find_smallest(*s_a)->content)
	{
		if (ft_find_smallest(*s_a)->above_median)
			ft_ra(s_a, false);
		else
			ft_rra(s_a , false);
	}
	return (true);
}