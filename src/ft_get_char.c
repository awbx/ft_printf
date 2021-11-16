/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:05:39 by asabani           #+#    #+#             */
/*   Updated: 2021/11/16 01:48:04 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	ft_get_char(const char c)
{
	t_arg	arg;

	arg.data = (char *)malloc(sizeof(char) * 2);
	if (!arg.data)
		return (arg);
	arg.length = 1;
	arg.data[0] = c;
	arg.data[1] = '\0';
	return (arg);
}
