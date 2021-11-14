/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:18:24 by asabani           #+#    #+#             */
/*   Updated: 2021/11/14 12:43:18 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_address(unsigned long addr)
{
	if (addr != 0)
	{
		print_address(addr / 16);
		ft_print_char(HEX_LOWERCASE[addr % 16]);
	}
}

void	ft_print_address(void *ptr)
{
	ft_print_char('0');
	ft_print_char('x');
	print_address((unsigned long)ptr);
}
