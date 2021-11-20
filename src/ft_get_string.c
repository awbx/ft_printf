/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:49:16 by asabani           #+#    #+#             */
/*   Updated: 2021/11/20 14:13:48 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*string_justify(const char *str, \
		size_t length, int amount, t_spec *spec)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (length + amount + 1));
	if (!new_str)
		return (NULL);
	if (spec->flags.left_justify)
	{
		ft_memcpy(new_str, str, length);
		ft_memset(new_str + length, ' ', amount);
	}
	else
	{
		ft_memset(new_str, ' ', amount);
		ft_memcpy(new_str + amount, str, length);
	}
	new_str[length + amount] = '\0';
	return (new_str);
}

t_arg	ft_get_string(const char *str, t_spec *spec)
{
	t_arg	arg;
	size_t	length;
	int		amount;

	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	if (spec->prec)
		length = ft_get_minimum(spec->length, length);
	amount = spec->width - length;
	if (amount < 0)
		amount = 0;
	arg.data = string_justify(str, length, amount, spec);
	arg.length = length + amount;
	return (arg);
}
