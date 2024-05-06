/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:36:42 by tbras             #+#    #+#             */
/*   Updated: 2024/02/22 15:36:42 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printchar(int i);
int	ft_printstr(char *str);
int	ft_printdigit(long nbr, int base, int trigger);
int	ft_printpoint(void *vp);
int	ft_print_neg_point(intptr_t vp);
int	ft_argprintf(const char *format, va_list *ap);
int	ft_strlen(char *str);

#endif
