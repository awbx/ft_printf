/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:23:39 by asabani           #+#    #+#             */
/*   Updated: 2021/11/19 01:34:44 by asabani          ###   ########.fr       */
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

int	print_to_stdout(t_spec *spec, va_list ap, const char *fmt)
{
	t_arg	arg;

	arg.data = NULL;
	if (spec->spec_type == CHARACTER_SPEC)
		arg = ft_get_char(va_arg(ap, int), spec);
	else if (spec->spec_type == STRING_SPEC)
		arg = ft_get_string(va_arg(ap, char *), spec);
	else if (spec->spec_type == POINTER_SPEC)
		arg = ft_get_address(va_arg(ap, void *), spec);
	else if (spec->spec_type == DECIMAL_SPEC || spec->spec_type == INTEGER_SPEC)
		arg = ft_get_number(va_arg(ap, int), spec);
	else if (spec->spec_type == UC_HEX_SPEC)
		arg = ft_get_number_base(va_arg(ap, unsigned int), 16, spec);
	else if (spec->spec_type == LC_HEX_SPEC)
		arg = ft_get_number_base(va_arg(ap, unsigned int), 16, spec);
	else if (spec->spec_type == UNSIGNED_SPEC)
		arg = ft_get_number_base(va_arg(ap, unsigned int), 10, spec);
	else if (spec->spec_type == PERCENT_SPEC)
		arg = ft_get_percent(spec);
	else if (spec->spec_type == UNKNWON_SPEC)
		arg = ft_get_unknown(*fmt);
	if (arg.data)
	{
		write(1, arg.data, arg.length);
		free(arg.data);
	}
	return (arg.length);
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
			printed_count += print_to_stdout(&spec, ap, fmt);
			fmt++;
			if (spec.spec_type != UNKNWON_SPEC)
				continue ;
			reset_spec(&spec);
		}
		ft_putchar(*fmt++);
		printed_count++;
	}
	va_end(ap);
	return (printed_count);
}
