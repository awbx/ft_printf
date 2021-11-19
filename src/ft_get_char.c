/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:05:39 by asabani           #+#    #+#             */
/*   Updated: 2021/11/18 12:12:30 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_arg	ft_get_char(const unsigned char c, t_spec *spec)
{
	t_arg	arg;
	int		amount;
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	arg.length = 1;
	amount = spec->width - 1;
	if (amount <= 0)
		arg.data = string_justify(str, 1, 0, spec->flags.left_justify);
	else
	{
		arg.data = string_justify(str, 1, amount, spec->flags.left_justify);
		arg.length += amount;
	}
	return (arg);
}
