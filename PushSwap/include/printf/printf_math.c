/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfmath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:21:45 by tbras             #+#    #+#             */
/*   Updated: 2024/02/08 18:21:46 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdigit(long nbr, int base, int trigger)
{
	int		count;
	char	*base_nbr_lower;
	char	*base_nbr_upper;
	char	*used;

	base_nbr_lower = "0123456789abcdef";
	base_nbr_upper = "0123456789ABCDEF";
	used = base_nbr_lower;
	if (trigger == 1)
		used = base_nbr_upper;
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (ft_printdigit(-nbr, base, trigger) + 1);
	}
	else if (nbr < base)
		return (ft_printchar(used[nbr]));
	else
	{
		count = ft_printdigit(nbr / base, base, trigger);
		return (count + ft_printdigit(nbr % base, base, trigger));
	}
}

int	ft_print_neg_point(intptr_t vp)
{
	int		index;
	int		remainder;
	char	*base;
	char	*address;

	base = "fedcba9876543210";
	index = sizeof(void *) * 2 - 1;
	address = malloc(sizeof(void *) * 2 + 1);
	if (!address)
		return (0);
	address[index + 1] = '\0';
	while (vp > 0)
	{
		remainder = vp % 16;
		address[index] = base[remainder];
		vp /= 16;
		index--;
	}
	while (index > -1)
		address[index--] = 'f';
	index = ft_printstr(address);
	free(address);
	return (index);
}

int	ft_printpoint(void *vp)
{
	int	count;

	count = 0;
	if (!vp)
		return (ft_printstr("(nil)"));
	count += ft_printstr("0x");
	if ((long)vp < 0)
		count += ft_print_neg_point((intptr_t)vp * -1 - 1);
	else
		count += ft_printdigit((long long)vp, 16, 0);
	return (count);
}
