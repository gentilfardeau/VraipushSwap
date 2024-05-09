#include "../include/push_swap.h"

// Gere la gestion des mouvements

// Synthetise et assemble le tri, et renvoie le nombre de moves
// Prend en compte : l'affectations du poids, de l'index final et des mouvements

bool ft_mini_sort(t_node **s_a)
{
	t_node *max;

	if (!s_a)
		return (false);
	max = ft_find_biggest(*s_a);
	if (max == (*s_a))
		ft_rotate_a(s_a, false);
	else if ((*s_a)->next == max)
		ft_rr_a(s_a, false);
	if ((*s_a)->content > (*s_a)->next->content)
		ft_swap_a(s_a, false);
	return (true);
}

bool ft_sorting(t_node **s_a, t_node **s_b)
{
	int len_a;

	if (!s_a || !s_b)
		return (false);
	len_a = ft_stack_len(*s_a);
	if (len_a-- > 3 && !ft_stack_sorted(*s_a))
		ft_push_b(s_a, s_b, false);
	if (len_a-- > 3 && !ft_stack_sorted(*s_a))
		ft_push_b(s_a, s_b, false);
	while (len_a-- > 3 && !ft_stack_sorted(*s_a))
	{
		if (!ft_set_nodes_a(*s_a, *s_b) || !ft_move_sort(*s_a, *s_b))
			return (false);
	}
	ft_mini_sort(s_a);
	while (s_b)
	{
		if (!ft_set_nodes_b(*s_b, *s_a) || !ft_move_sort(*s_b, *s_a))
			return (false);
	}
	ft_affect_current(*s_a);
	ft_final_sort(*s_a);
	return (true);
}