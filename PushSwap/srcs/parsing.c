#include "../include/push_swap.h"

// Permet de stocker les splits dans des nodes
bool	ft_split_init(char *str, t_node **s_a)
{
	int		i;
	int		value;
	char	**split;

	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
	{
		if (!ft_check_digit(split[i], false))
			return (false);
		value = ft_atol(split[i]);
		if (ft_atol_checked(value))
			ft_node_addback((int)value, s_a);
		i++;
	}
	while (i--)
		free(split[i]);
	free(split);
	return (true);
}

// Englobe le parsing et initialise la stack A
bool	ft_parsing(char **argv, t_node **s_a)
{
	int		i;
	long	nb;

	if (!argv || !s_a)
		return (false);
	i = 1;
	while (argv[i])
	{
		if (ft_space_found(argv[i]) > 1)
		{
			if (!ft_split_init(argv[i], s_a))
				return (false);
		}
		else if (ft_check_digit(argv[i], false))
		{
			nb = ft_atol(argv[i]);
			if (ft_atol_checked(nb))
				ft_node_addback((int)nb, s_a);
		}
		else
			return (false);
		i++;
	}
	if (!ft_check_double(*s_a) || ft_stack_sorted(*s_a))
		return (false);
	return (true);
}
