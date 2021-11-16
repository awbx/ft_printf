/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:56:20 by asabani           #+#    #+#             */
/*   Updated: 2021/11/16 21:51:00 by asabani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define UC_HEX_BASE "0123456789ABCDEF"
# define LC_HEX_BASE "0123456789abcdef"
# define DECIMAL_BASE "0123456789"
# define FLAGS "# +-0."

int		ft_printf(const char *fmt, ...);

// specifier helpers
typedef enum e_spec_type
{
	CHARACTER_SPEC='c',
	STRING_SPEC='s',
	POINTER_SPEC='p',
	DECIMAL_SPEC='d',
	INTEGER_SPEC='i',
	UNSIGNED_SPEC='u',
	UC_HEX_SPEC='X',
	LC_HEX_SPEC='x',
	PERCENT_SPEC='%',
	UNKNWON_SPEC='\0'
}	t_spec_type;

typedef struct s_spec
{
	t_spec_type	spec_type;
}	t_spec;

void	reset_spec(t_spec *spec);
int		check_spec_type(t_spec *spec, const char *fmt);

// global utils prototype
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
size_t	ft_count_digits(unsigned long num, int base);
void	ft_putchar(const char c);

// print functions prototype
typedef struct s_arg
{
	char	*data;
	size_t	length;
}	t_arg;
t_arg	ft_get_char(const char c);
t_arg	ft_get_string(const char *str);
t_arg	ft_get_address(const void *ptr);
t_arg	ft_get_number(int number);
t_arg	ft_get_number_base(unsigned int number, int radix, char *base);
t_arg	ft_get_percent(void);
t_arg	ft_get_unknown(char c);
#endif
