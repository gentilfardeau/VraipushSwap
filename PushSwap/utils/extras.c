#include "../include/push_swap.h"

int ft_strcmp(char *s1, char *s2) 
{
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

void ft_print_stack_content(t_node *stack, char *content)
{
	int i;
	char *content_array[7] = {"content", "above_median", "cost", "target_node", "current_pos", "previous", "next"};

	i = 0;
	while (ft_strcmp(content, content_array[i]))
		i++;
	while(stack)
	{
		if (i == 0)
			ft_printf("Content of the node : %d \n", stack->content);
		if (i == 1)
		{
			if(stack->above_median == true)
				ft_printf("Node above median \n");
			if(stack->above_median == false)
				ft_printf("Node below median \n");
		}
		if (i == 2)
			ft_printf("%d Cost of the node : %d \n",stack->content,stack->cost);
		if (i == 3)
		{
			if (stack->target_node)
				ft_printf("%d Target node of the node : %d \n", stack->target_node->content ,stack->content);
			else
				ft_printf("Target node not found.\n");
		}
		if (i == 4)
			ft_printf("Current pos of the node : %d \n", stack->current_pos);
		if (i == 5)
		{
			if (!stack->previous)
				ft_printf("%d Is the first of the stack \n", stack->content);
			else 
				ft_printf("%d Previous node is : %d \n", stack->content, stack->previous->content);
		}
		if (i == 6)
		{
			if (!stack->next)
				ft_printf("%d Is the last of the stack \n", stack->content);
			else
				ft_printf("%d Next node is : %d \n", stack->content, stack->next->content);
		}
		stack = stack->next;
	}
	ft_printf("  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
}