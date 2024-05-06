#include "../include/push_swap.h"

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
    return (newnode);
}

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

// Ajoute le noeud a la fin
void ft_node_addback (t_node *new, t_node **stack)
{
	t_node *tmp;

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

// Imprime les contenus stack
void ft_print_stack(t_node *stack)
{
	while (stack)
	{
		ft_printf("%d \n", stack->content);
		stack = stack->next;
	}
	return;
}