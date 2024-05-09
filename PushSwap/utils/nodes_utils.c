#include "../include/push_swap.h"

// Trouve le dernier noeud de la liste
t_node	*ft_node_findlast (t_node *list)
{
	if (!list)
		return (NULL);
	while (list)
	{
		if (list->next ==NULL)
			return (list);
		list = list->next;
	}
	return (list);
}

// Compte le nombre de noeuds d'une stack
int ft_stack_len(t_node *stack)
{
	int i;

	i = 0;
	while(stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

// Trouve le noeud avec le plus petit content
t_node *ft_find_smallest(t_node *stack)
{
	t_node *tmp;
	
	tmp = stack;
	while (stack)
	{
		if (stack->content < tmp->content)
			tmp= stack;
		stack = stack->next;
	}
	return (tmp);
}

t_node *ft_find_biggest(t_node *stack)
{
	t_node *tmp;
	
	tmp = stack;
	while (stack)
	{
		if (stack->content > tmp->content)
			tmp= stack;
		stack = stack->next;
	}
	return (tmp);
}