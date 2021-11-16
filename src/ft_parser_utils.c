/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:23:42 by asabani           #+#    #+#             */
/*   Updated: 2021/11/16 21:45:33 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_spec(t_spec *spec)
{
	spec->spec_type = UNKNWON_SPEC;
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
