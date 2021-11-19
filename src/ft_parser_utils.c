/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:23:42 by asabani           #+#    #+#             */
/*   Updated: 2021/11/19 17:00:42 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_spec(t_spec *spec)
{
	t_flags	flags;

	flags.left_justify = 0;
	flags.zero_padded = 0;
	flags.sign = 0;
	flags.hash = 0;
	flags.blank = 0;
	spec->flags = flags;
	spec->width = 0;
	spec->prec = 0;
	spec->length = 0;
	spec->spec_type = UNKNWON_SPEC;
}

int	check_flags(t_spec *spec, const char *fmt)
{
	int	i;

	i = 0;
	while (fmt[i] && ft_strchr(FLAGS, fmt[i]))
	{
		if (fmt[i] == '-')
			spec->flags.left_justify = 1;
		else if (fmt[i] == '0')
			spec->flags.zero_padded = 1;
		else if (fmt[i] == '+')
			spec->flags.sign = 1;
		else if (fmt[i] == ' ')
			spec->flags.blank = 1;
		else if (fmt[i] == '#')
			spec->flags.hash = 1;
		else
			break ;
		i++;
	}
	return (i);
}

int	check_minimum_width(t_spec *spec, const char *fmt)
{
	int	width;
	int	i;

	i = 0;
	width = 0;
	while (fmt[i] && ft_isdigit(fmt[i]))
	{
		width = width * 10 + fmt[i] - '0';
		i++;
	}
	spec->width = width;
	return (i);
}

int	check_maximum_width(t_spec *spec, const char *fmt)
{
	int	i;
	int	length;

	i = 1;
	length = 0;
	spec->prec = 1;
	while (fmt[i] && ft_isdigit(fmt[i]))
	{
		length = length * 10 + fmt[i] - '0';
		i++;
	}
	spec->length = length;
	return (i);
}

int	check_spec_type(t_spec *spec, const char *fmt)
{
	if (*fmt == CHARACTER_SPEC)
		spec->spec_type = CHARACTER_SPEC;
	else if (*fmt == STRING_SPEC)
		spec->spec_type = STRING_SPEC;
	else if (*fmt == POINTER_SPEC)
		spec->spec_type = POINTER_SPEC;
	else if (*fmt == DECIMAL_SPEC)
		spec->spec_type = DECIMAL_SPEC;
	else if (*fmt == INTEGER_SPEC)
		spec->spec_type = INTEGER_SPEC;
	else if (*fmt == UNSIGNED_SPEC)
		spec->spec_type = UNSIGNED_SPEC;
	else if (*fmt == LC_HEX_SPEC)
		spec->spec_type = LC_HEX_SPEC;
	else if (*fmt == UC_HEX_SPEC)
		spec->spec_type = UC_HEX_SPEC;
	else if (*fmt == PERCENT_SPEC)
		spec->spec_type = PERCENT_SPEC;
	else
		spec->spec_type = UNKNWON_SPEC;
	return (1);
}
