/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:32:20 by asabani           #+#    #+#             */
/*   Updated: 2021/11/18 12:01:57 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	ft_get_percent(t_spec *spec)
{
	t_arg	arg;
	char	str[2];

	str[0] = '%';
	str[1] = '\0';
	arg = ft_get_string(str, spec);
	return (arg);
}
