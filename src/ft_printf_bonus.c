/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:23:39 by asabani           #+#    #+#             */
/*   Updated: 2021/11/20 00:33:41 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_spec(t_spec *spec, const char *fmt)
{
	int	i;

	i = 1;
	i += check_flags(spec, fmt + i);
	i += check_minimum_width(spec, fmt + i);
	if (fmt[i] && fmt[i] == '.')
		i += check_maximum_width(spec, fmt + i);
	check_spec_type(spec, fmt + i);
	return (i);
}

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
			fmt += parse_spec(&spec, fmt);
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
