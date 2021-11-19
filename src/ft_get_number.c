/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:21:11 by asabani           #+#    #+#             */
/*   Updated: 2021/11/19 01:33:12 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int	get_maximum(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	numcpy(char *str, char *base, \
		unsigned long int number, size_t length)
{
	int	radix;

	radix = ft_strlen(base);
	while (length--)
	{
		str[length] = base[number % radix];
		number /= radix;
	}
}

t_arg	number_justify(unsigned long int number, \
		size_t	length, int amount, t_spec *spec)
{
	t_arg	arg;
	char	*base;

	base = LC_HEX_BASE;
	if (spec->spec_type == UNSIGNED_SPEC || \
			spec->spec_type == DECIMAL_SPEC || spec->spec_type == INTEGER_SPEC)
		base = DECIMAL_BASE;
	else if (spec->spec_type == UC_HEX_SPEC)
		base = UC_HEX_BASE;
	arg.length = length;
	arg.data = (char *)malloc(sizeof(char) * (length + 1));
	if (spec->flags.left_justify)
	{
		numcpy(arg.data, base, number, length - amount);
		memset(arg.data + (length - amount), ' ', amount);
	}
	else
	{
		if (spec->flags.zero_padded)
			memset(arg.data, '0', amount);
		else
			memset(arg.data, ' ', amount);
		numcpy(arg.data + amount, base, number, length - amount);
	}
	return (arg);
}

void	add_sign(t_arg *arg, t_spec *spec, int amount, int isnegative)
{
	char	sign;

	sign = '\0';
	if (isnegative)
		sign = '-';
	else if (spec->flags.blank)
		sign = ' ';
	else if (spec->flags.sign)
		sign = '+';
	if (arg->data && sign)
	{
		if (spec->flags.left_justify || spec->flags.zero_padded)
			arg->data[0] = sign;
		else
			arg->data[amount] = sign;
	}
}

t_arg	ft_get_number(int number, t_spec *spec)
{
	t_arg		arg;
	size_t		length;
	int			amount;
	long int	nb;

	length = 0;
	nb = number;
	if (number <= 0)
		nb *= -1;
	if (spec->flags.sign || spec->flags.blank)
		length++;
	if (spec->spec_type == POINTER_SPEC || (spec->flags.hash && number))
		length += 2;
	length += ft_count_digits(nb, 10);
	if (spec->prec)
		length = get_maximum(spec->length, length);
	if (number <= 0)
		length++;
	amount = spec->width - length;
	if (amount < 0)
		amount = 0;
	length += amount;
	arg = number_justify(nb, length, amount, spec);
	// handle sign 
	//add_sign(&arg, spec, amount, number < 0 ? 1: 0);
	arg.data[length] = '\0';
	return (arg);
}

void	add_prefix(t_arg *arg, t_spec *spec, int amount)
{
	char	prefix;

	prefix = 'x';
	if (spec->spec_type == UC_HEX_SPEC)
		prefix = 'X';
	if (arg->data)
	{
		if (spec->flags.left_justify || spec->flags.zero_padded)
			arg->data[1] = prefix;
		else
			arg->data[amount +1] = prefix;
	}
}

t_arg	ft_get_number_base(unsigned long int number, int radix, t_spec *spec)
{
	t_arg	arg;
	size_t	length;
	int		amount;

	length = 0;
	if (number == 0)
		length++;
	if (spec->spec_type == POINTER_SPEC || (spec->flags.hash && number))
		length += 2;
	length += ft_count_digits(number, radix);
	if (spec->prec)
		length = get_maximum(spec->length, length);
	amount = spec->width - length;
	if (amount < 0)
		amount = 0;
	length += amount;
	arg = number_justify(number, length, amount, spec);
	if (spec->spec_type == POINTER_SPEC || (spec->flags.hash && number))
		add_prefix(&arg, spec, amount);
	arg.data[length] = '\0';
	return (arg);
}
