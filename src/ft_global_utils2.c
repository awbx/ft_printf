/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:51:35 by asabani           #+#    #+#             */
/*   Updated: 2021/11/19 19:11:56 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_get_minimum(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_get_maximum(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_numcpy(char *str, char *base, \
		unsigned long int number, size_t length)
{
	int	radix;

	radix = ft_strlen(base);
	while (length--)
	{
		str[length] = base[number % radix];
		number /= radix;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!(dst || src))
		return (0);
	i = -1;
	while (++i < n)
		*((char *)dst + i) = *((char *) src + i);
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		*((unsigned char *)b + i) = (unsigned char)c;
	return (b);
}
