/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:05:39 by asabani           #+#    #+#             */
/*   Updated: 2021/11/19 19:29:07 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	ft_get_char(const unsigned char c, t_spec *spec)
{
	t_arg	arg;
	int		amount;
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	arg.length = 1;
	amount = spec->width - 1;
	if (amount < 0)
		amount = 0;
	arg.data = string_justify(str, 1, amount, spec);
	arg.length += amount;
	return (arg);
}
