#include "../include/push_swap.h"

// Print error en cas de besoin
int ft_error_message (void)
{
	ft_printf("Error\n");
    return (1);
}

// Free le tableau utilise par split
void ft_abort_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return;
}