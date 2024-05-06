#include "../include/push_swap.h"

int ft_write(char *str)
{
    if (!str)
        return (1);
    write(1, str, ft_strlen(str));
    return (0);
}

int ft_write_digit(char nb)
{
    if (!nb)
        return (1);
    write(1, &nb, 1);
    return (0);
}

