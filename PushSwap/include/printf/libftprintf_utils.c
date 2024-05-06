/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:40:52 by tbras             #+#    #+#             */
/*   Updated: 2024/02/09 17:40:53 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printchar(int i)
{
	char	c;

	c = i;
	write (1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (ft_printstr("(null)"));
	while (str[counter])
	{
		write (1, &str[counter], 1);
		counter++;
	}
	return (counter);
}
