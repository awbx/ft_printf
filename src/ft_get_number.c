/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:21:11 by asabani           #+#    #+#             */
/*   Updated: 2021/11/20 00:22:51 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_arg	number_justify(unsigned long int number, \
		size_t	length, int amount, t_spec *spec)
{
	t_arg	arg;
	char	*base;

	base = choice_base(spec->spec_type);
	arg.length = length + amount;
	arg.data = (char *)malloc(sizeof(char) * (arg.length + 1));
	if (!arg.data)
		return (arg);
	if (spec->flags.left_justify)
	{
		ft_numcpy(arg.data, base, number, length);
		ft_memset(arg.data + length, ' ', amount);
	}
	else
	{
		if (spec->flags.zero_padded && spec->prec == 0)
			ft_memset(arg.data, '0', amount);
		else
			ft_memset(arg.data, ' ', amount);
		ft_numcpy(arg.data + amount, base, number, length);
	}
	arg.data[arg.length] = '\0';
	return (arg);
}

static	void	add_sign(t_arg *arg, t_spec *spec, int amount, int number)
{
	char	sign;

	sign = '\0';
	if (number < 0)
		sign = '-';
	else if (spec->flags.blank)
		sign = ' ';
	else if (spec->flags.sign)
		sign = '+';
	if (arg->data && sign)
	{
		if (spec->flags.left_justify || \
				(spec->flags.zero_padded && spec->prec == 0))
			arg->data[0] = sign;
		else
			arg->data[amount] = sign;
	}
}

static	void	add_prefix(t_arg *arg, t_spec *spec, int amount)
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

t_arg	ft_get_number(int number, t_spec *spec)
{
	t_arg		arg;
	size_t		length;
	int			amount;
	long int	nb;

	length = 0;
	nb = number;
	if (number < 0)
		nb *= -1;
	length += ft_count_digits(nb, 10);
	if (spec->prec)
	{
		length = ft_get_maximum(spec->length, length);
		if (spec->length == 0 && number == 0)
			length--;
	}	
	if (number < 0 || spec->flags.sign || spec->flags.blank)
		length++;
	amount = spec->width - length;
	if (amount < 0)
		amount = 0;
	arg = number_justify(nb, length, amount, spec);
	add_sign(&arg, spec, amount, number);
	return (arg);
}

t_arg	ft_get_number_base(unsigned long int number, int radix, t_spec *spec)
{
	t_arg	arg;
	size_t	length;
	int		amount;

	length = 0;
	if (spec->spec_type == POINTER_SPEC || (spec->flags.hash && number))
		length += 2;
	length += ft_count_digits(number, radix);
	if (spec->prec)
	{
		length = ft_get_maximum(spec->length, length);
		if (spec->length == 0 && number == 0)
			length--;
	}
	amount = spec->width - length;
	if (amount < 0)
		amount = 0;
	arg = number_justify(number, length, amount, spec);
	if (spec->spec_type == POINTER_SPEC || (spec->flags.hash && number))
		add_prefix(&arg, spec, amount);
	return (arg);
}
