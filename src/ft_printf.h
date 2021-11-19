/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:56:20 by asabani           #+#    #+#             */
/*   Updated: 2021/11/19 00:22:12 by asabani          ###   ########.fr       */
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

typedef struct s_flags
{
	int	left_justify;
	int	zero_padded;
	int	sign;
	int	blank;
	int	hash;
}	t_flags;

typedef struct s_spec
{
	t_flags		flags;
	size_t		width;
	int			prec;
	size_t		length;
	t_spec_type	spec_type;
}	t_spec;

void	reset_spec(t_spec *spec);
int		check_flags(t_spec *spec, const char *fmt);
int		check_minimum_width(t_spec *spec, const char *fmt);
int		check_maximum_width(t_spec *spec, const char *fmt);
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
t_arg	ft_get_char(const unsigned char c, t_spec *spec);
t_arg	ft_get_string(const char *str, t_spec *spec);
t_arg	ft_get_address(const void *ptr, t_spec *spec);
t_arg	ft_get_number(int number, t_spec *spec);
t_arg	ft_get_number_base(unsigned long int number, int radix, t_spec *spec);
t_arg	ft_get_percent(t_spec *spec);
t_arg	ft_get_unknown(char c);
char	*string_justify(const char *str, size_t length, int amount, \
		int left_justify);
size_t	get_minimum(size_t a, size_t b);
#endif
