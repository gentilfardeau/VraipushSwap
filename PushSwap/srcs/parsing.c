#include "../include/push_swap.h"

// Parcour le chiffre en char pour voir si le format correspond
int ft_check_digit(char *str, bool space)
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
			return (1);
		i++;
	}
	return (0);
}

// Trouve les doubles une fois la stack initialisee
int ft_find_double(t_node *stack)
{
	int value;

	while (stack)
	{
		value = stack->content;
		while (stack->next != NULL)
		{
			stack = stack->next;
			if (value == stack->content)
				return (1);
		}
		stack = stack->next;
	}
	return (0);
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



// Permet de stocker les splits dans des nodes
int ft_split_init(char *str, t_node **stack_a)
{
	int i;
	int value;
	char **split;
	t_node *new;

	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
	{
		if (ft_check_digit(split[i], true))
			return (1);
		value = ft_atoi(split[i]);
		new = ft_node_init(value);
		ft_node_addback(new, stack_a);
		i++;
	}
	return (0);
}

// Englobe le parsing et initialise la stack A
int ft_parsing(char **argv, t_node **stack_a)
{
	int i;
	t_node *new;

	if (!argv)
		return (1);
	i = 1;
	while (argv[i])
	{
		if (ft_space_found(argv[i]) > 1)
		{
			if (ft_split_init(argv[i], stack_a))
				return (1);
		}
		else if (ft_check_digit(argv[i], true))
			return (1);
		else 
		{
			new = ft_node_init(ft_atoi(argv[i]));
			ft_node_addback(new, stack_a);
		}
		if (ft_find_double(*stack_a))
			return (1);
		i++;
	}
	return (0);
}
