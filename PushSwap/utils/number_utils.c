#include "../include/push_swap.h"
bool ft_atol_checked(long nb)
{
	if (nb > 2147483647 || nb < -2147483648  )
		return (false);
	return (true);
}

long ft_atol(const char *nptr)
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
	return (nb);
}
