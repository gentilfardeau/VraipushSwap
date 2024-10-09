#include "../../include/push_swap.h"

// Push d'une stack a l'autre
bool	ft_push(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (!dst || !src)
		return (false);
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	return (true);
}

// Push de B vers A
bool	ft_push_a(t_node **s_a, t_node **s_b, bool checker)
{
	if (!s_a || !s_b)
		return (false);
	ft_push(s_b, s_a);
	if (checker)
		ft_printf("pa\n");
	return (true);
}

// Push de A vers B
bool	ft_push_b(t_node **s_a, t_node **s_b, bool checker)
{
	if (!s_a || !s_b)
		return (false);
	ft_push(s_a, s_b);
	if (checker)
		ft_printf("pb\n");
	return (true);
}
