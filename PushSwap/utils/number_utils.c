#include "../include/push_swap.h"

long ft_atoi(const char *nptr)
{
	long	i;
	long	nb;
	long	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = (nb * 10) + (nptr[i++] - '0');
	nb *= sign;
	if (nb > 2147483647 || nb < -2147483648 )
		return (0);
	return (nb);
}