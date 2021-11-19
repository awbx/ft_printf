/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:37:23 by asabani           #+#    #+#             */
/*   Updated: 2021/11/19 22:45:44 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_output(t_arg arg)
{
	if (arg.data)
	{
		write(1, arg.data, arg.length);
		free(arg.data);
	}
}

int	ft_print_to_stdout(t_spec *spec, va_list ap, const char *fmt)
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
		arg = ft_get_unknown(*fmt, spec);
	handle_output(arg);
	return (arg.length);
}

char	*choice_base(t_spec_type spec_type)
{
	char	*base;

	base = LC_HEX_BASE;
	if (spec_type == UNSIGNED_SPEC || \
			spec_type == DECIMAL_SPEC || spec_type == INTEGER_SPEC)
		base = DECIMAL_BASE;
	else if (spec_type == UC_HEX_SPEC)
		base = UC_HEX_BASE;
	return (base);
}
