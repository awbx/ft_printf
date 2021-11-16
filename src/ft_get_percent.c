/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:32:20 by asabani           #+#    #+#             */
/*   Updated: 2021/11/16 15:41:41 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	ft_get_percent(void)
{
	t_arg	arg;

	arg.data = (char *)malloc(sizeof(char) * 2);
	if (!arg.data)
		return (arg);
	arg.data[0] = '%';
	arg.data[1] = '\0';
	arg.length = 1;
	return (arg);
}
