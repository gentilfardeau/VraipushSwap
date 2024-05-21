#include "../include/push_swap.h"

// Trouve les doubles une fois la stack initialisee
bool ft_check_double(t_node *stack)
{
	int value;
	t_node *tmp;

	while (stack)
	{
		tmp = stack->next;
		value = stack->content;
		while (tmp)
		{
			if (tmp->content == value)
				return (false);
			tmp = tmp -> next;
		}
		stack = stack->next;
	}
	return (true);
}

// Parcour le chiffre en char pour voir si le format correspond
bool ft_check_digit(char *str, bool space)
{
	int i;
	int trigger;

	i = 0;
	while (str[i])
	{
		trigger = 0;
		if ((str[i] == '-' || str[i] == '+') && i == 0)
			trigger = 1;
		else if (str[i] == ' ' && space == true)
			trigger = 1;
		if ((str[i] < '0' || str[i] > '9') && trigger == 0)
			return (false);
		i++;
	}
	return (true);
}

// Trouver les espaces dans les strings
int ft_space_found(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str[0] != ' ')
		count++;
	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}
