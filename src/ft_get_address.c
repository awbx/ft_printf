/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:48:54 by asabani           #+#    #+#             */
/*   Updated: 2021/11/16 15:20:17 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	ft_get_address(const void *ptr)
{
	t_arg			arg;
	size_t			length;
	unsigned long	addr;

	addr = (unsigned long)ptr;
	length = ft_count_digits(addr, 16) + 2;
	if (!ptr)
		length++;
	arg.data = (char *)malloc(sizeof(char) * (length + 1));
	if (!arg.data)
		return (arg);
	arg.length = length;
	arg.data[length--] = '\0';
	while (addr != 0)
	{
		arg.data[length--] = LC_HEX_BASE[addr % 16];
		addr /= 16;
	}
	arg.data[0] = '0';
	arg.data[1] = 'x';
	if (!ptr)
		arg.data[2] = '0';
	return (arg);
}
