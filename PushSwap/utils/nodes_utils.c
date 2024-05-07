#include "../include/push_swap.h"

// Trouve le dernier noeud de la liste
t_node *ft_node_findlast (t_node *list)
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

// Initialise les noeuds individuellement
t_node *ft_node_init (int value)
{
    t_node *newnode;

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
void ft_node_addback (int content, t_node **stack)
{
	t_node *tmp;
	t_node *new;

	new = ft_node_init(content);
	if (!new)
		return;
	if (stack)
	{
		if(*stack == NULL)
			*stack = new;
		else 
		{
			tmp = ft_node_findlast(*stack);
			tmp->next = new;
			new->previous = tmp;	
		}
	}
	return;
}
