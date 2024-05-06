/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:20:24 by tbras             #+#    #+#             */
/*   Updated: 2024/02/08 18:20:28 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_argprintf(const char *format, va_list *ap)
{
	int	printed;

	printed = 0;
	if (*format)
	{
		if (*format == 'c')
			printed += ft_printchar(va_arg(*ap, int));
		else if (*format == 's')
			printed += ft_printstr(va_arg(*ap, char *));
		else if (*format == 'p')
			printed += ft_printpoint(va_arg(*ap, void *));
		else if (*format == 'd' || *format == 'i')
			printed += ft_printdigit((long)va_arg(*ap, int), 10, 0);
		else if (*format == 'u')
			printed += ft_printdigit(va_arg(*ap, unsigned int), 10, 0);
		else if (*format == 'x')
			printed += ft_printdigit((long)va_arg(*ap, unsigned int), 16, 0);
		else if (*format == 'X')
			printed += ft_printdigit((long)va_arg(*ap, unsigned int), 16, 1);
		else if (*format == '%')
			printed += ft_printchar('%');
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			counter;

	counter = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			counter += ft_argprintf(format, &ap);
		}
		else
			counter += ft_printchar(*format);
		format++;
	}
	va_end(ap);
	return (counter);
}
