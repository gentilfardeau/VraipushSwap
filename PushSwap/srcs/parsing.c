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
			if (tmp->content == stack->content)
				return (false);
			tmp = tmp -> next;
		}
		stack = stack->next;
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



// Permet de stocker les splits dans des nodes
bool ft_split_init(char *str, t_node **stack_a)
{
	int i;
	int value;
	char **split;

	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
	{
		if (ft_check_digit(split[i], true))
			return (false);
		value = ft_atol(split[i]);
		if (ft_atoi_checked(value))
			ft_node_addback((int)value, stack_a);
		i++;
	}
	while (i--)
		free(split[i]);
	free(split);
	return (true);
}
 
// Englobe le parsing et initialise la stack A
bool ft_parsing(char **argv, t_node **stack_a)
{
	int i;
	long nb;

	if (!argv || !stack_a)
		return (false);
	i = 1;
	while (argv[i])
	{
		if (ft_space_found(argv[i]) > 1)
		{
			if (!ft_split_init(argv[i], stack_a))
				return (false);
		}
		else
		{
			nb = ft_atol(argv[i]);
			if (ft_atoi_checked(nb))
				ft_node_addback((int)nb, stack_a);
		}
		i++;
	}
	if (!ft_check_double(*stack_a))
		return (false);
	return (true);
}
