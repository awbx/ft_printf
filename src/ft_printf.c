/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:56:10 by asabani           #+#    #+#             */
/*   Updated: 2021/11/20 00:32:32 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		printed_count;
	va_list	ap;
	t_spec	spec;

	va_start(ap, fmt);
	printed_count = 0;
	while (*fmt)
	{
		reset_spec(&spec);
		if (*fmt == '%')
		{
			fmt++;
			check_spec_type(&spec, fmt);
			ft_print_to_stdout(&spec, ap, fmt++, &printed_count);
			if (printed_count == -1)
				return (-1);
			if (spec.spec_type != UNKNWON_SPEC)
				continue ;
		}
		ft_putchar(*fmt++);
		printed_count++;
	}
	va_end(ap);
	return (printed_count);
}
