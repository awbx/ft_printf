/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:49:16 by asabani           #+#    #+#             */
/*   Updated: 2021/11/19 01:18:49 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdio.h>

size_t	get_minimum(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

void	space_filler(char *str, int amount)
{
	int	i;

	i = -1;
	while (++i < amount)
		*(str + i) = ' ';
}

char	*string_justify(const char *str, \
		size_t length, int amount, int left_justify)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (length + amount + 1));
	if (left_justify)
	{
		memcpy(new_str, str, length);
		memset(new_str + length, ' ', amount);
	}
	else
	{
		memset(new_str, ' ', amount);
		memcpy(new_str + amount, str, length);
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
		length = get_minimum(spec->length, length);
	arg.length = length;
	amount = spec->width - length;
	if (amount <= 0)
		amount = 0;
	arg.length += amount;
	arg.data = string_justify(str, length, amount, spec->flags.left_justify);
	return (arg);
}
