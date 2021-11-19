/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:48:54 by asabani           #+#    #+#             */
/*   Updated: 2021/11/19 19:29:14 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	ft_get_address(const void *ptr, t_spec *spec)
{
	t_arg			arg;
	unsigned long	addr;

	addr = 0;
	if (ptr)
		addr = (unsigned long)ptr;
	arg = ft_get_number_base(addr, 16, spec);
	return (arg);
}
