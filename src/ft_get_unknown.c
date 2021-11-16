/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_unknown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:39:48 by asabani           #+#    #+#             */
/*   Updated: 2021/11/16 18:44:08 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	ft_get_unknown(char c)
{
	t_arg	arg;

	arg.data = (char *)malloc(sizeof(char) * 2);
	if (!arg.data)
		return (arg);
	arg.data[0] = c;
	arg.data[1] = '\0';
	arg.length = 1;
	return (arg);
}
