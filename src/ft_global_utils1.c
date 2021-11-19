/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:42:35 by asabani           #+#    #+#             */
/*   Updated: 2021/11/19 18:51:01 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (*(s + ++i))
		if (*(s + i) == (char)c)
			return ((char *)s + i);
	if (c == '\0')
		return ((char *)s + i);
	return ((char *)0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

size_t	ft_count_digits(unsigned long num, int base)
{
	size_t	digits;

	digits = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		digits++;
		num /= base;
	}
	return (digits);
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}
