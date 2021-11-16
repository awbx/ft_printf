/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:21:11 by asabani           #+#    #+#             */
/*   Updated: 2021/11/16 15:25:17 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

t_arg	ft_get_number(int number)
{
	t_arg		arg;
	long int	nb;
	size_t		length;

	nb = number;
	length = 0;
	if (nb <= 0)
	{
		nb *= -1;
		length++;
	}
	length += ft_count_digits(nb, 10);
	arg.data = (char *)malloc(sizeof(char) * (length + 1));
	if (!arg.data)
		return (arg);
	arg.length = length;
	arg.data[length] = '\0';
	while (length--)
	{	
		arg.data[length] = DECIMAL_BASE[nb % 10];
		nb /= 10;
	}
	if (number < 0)
		arg.data[0] = '-';
	return (arg);
}

t_arg	ft_get_number_base(unsigned int number, int radix, char *base)
{
	t_arg	arg;
	size_t	length;

	length = 0;
	if (number == 0)
		length++;
	length += ft_count_digits(number, radix);
	arg.data = (char *)malloc(sizeof(char) * (length + 1));
	arg.length = length;
	if (!arg.data)
		return (arg);
	arg.data[length] = '\0';
	while (length--)
	{
		arg.data[length] = base[number % radix];
		number /= radix;
	}
	return (arg);
}
