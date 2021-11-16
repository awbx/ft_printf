/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:49:16 by asabani           #+#    #+#             */
/*   Updated: 2021/11/16 17:22:45 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

t_arg	ft_get_string(const char *str)
{
	t_arg	arg;
	size_t	i;
	size_t	length;

	if (!str)
	{
		arg.data = strdup("(null)");
		arg.length = 6;
	}
	else
	{
		length = ft_strlen(str);
		arg.data = (char *)malloc(sizeof(char) * (length + 1));
		if (!arg.data)
			return (arg);
		arg.length = length;
		i = 0;
		while (i < length)
		{
			arg.data[i] = str[i];
			i++;
		}
		arg.data[i] = '\0';
	}
	return (arg);
}
