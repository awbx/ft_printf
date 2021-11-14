/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:56:20 by asabani           #+#    #+#             */
/*   Updated: 2021/11/14 13:02:06 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UPPERCASE "0123456789ACBDEF"
# define HEX_LOWERCASE "0123456789abcdef"

int		ft_printf(const char *fmt, ...);

// print functions prototype
void	ft_print_char(char c);
void	ft_print_string(char *str, size_t max_len);
void	ft_print_address(void *ptr);
#endif
