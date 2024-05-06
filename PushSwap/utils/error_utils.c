#include "../include/push_swap.h"

int ft_error_message (void)
{
    char *str;

    str = "Error\n";
    ft_write(str);
    return (1);
}

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