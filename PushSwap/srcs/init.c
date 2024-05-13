#include "../include/push_swap.h"

// Initialise les noeuds individuellement
t_node	*ft_node_init(int value)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->content = value;
	newnode->next = NULL;
	newnode->previous = NULL;
	newnode->target_node = NULL;
	newnode->cheapest = false;
	return (newnode);
}

// Ajoute le noeud a la fin
void	ft_node_addback(int content, t_node **stack)
{
	t_node	*tmp;
	t_node	*new;

	new = ft_node_init(content);
	if (!new)
		return ;
	if (stack)
	{
		if (*stack == NULL)
			*stack = new;
		else 
		{
			tmp = ft_node_findlast(*stack);
			tmp->next = new;
			new->previous = tmp;	
		}
	}
	return ;
}
bool	ft_set_nodes_a(t_node *s_a, t_node *s_b)
{
	if (!ft_affect_current(s_a))
		ft_printf("Puteuh 1\n");
	if (!ft_affect_current(s_b))
		ft_printf("Puteuh 2\n");
	if (!ft_find_target_node(s_a, s_b))
		ft_printf("Puteuh 3\n");
	if (!ft_affect_cost(s_a, s_b))
		ft_printf("Puteuh 4\n");
	if (!ft_affect_cheapest(s_a))
		ft_printf("Puteuh 5\n");
	return (true);
}

// bool	ft_set_nodes_a(t_node *s_a, t_node *s_b)
// {
// 	if (!s_a || !s_b)
// 		return (false);
// 	if (!ft_affect_current(s_a) || !ft_affect_current(s_b)
// 		|| !ft_find_target_node(s_a, s_b) || !ft_affect_cost(s_a, s_b)
// 		|| !ft_find_cheapest(s_a))
// 	{
// 		ft_printf("Puteuh 1\n");
// 		return (false);
// 	}
// 	return (true);
// }

bool	ft_set_nodes_b(t_node *s_b, t_node *s_a)
{
	if (!s_b)
		ft_printf("Ya pas wesh");
	if (!ft_affect_current(s_a))
		ft_printf("Suce 1\n");
	if (!ft_affect_current(s_b))
		ft_printf("Suce 2\n");
	if  (!ft_find_target_node(s_a, s_b))
		ft_printf("Suce 4\n");
	if  (!ft_find_target_node(s_b, s_a))
		ft_printf("Suce 3\n");
	return (true);
}