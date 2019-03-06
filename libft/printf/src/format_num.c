/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:01:42 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/23 09:50:19 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include "ft_printf_internals.h"

int	format_integer(t_arg *arg)
{
	char			buff[BUFFER_CONVERSION_MAX];
	unsigned int	prefixes;
	size_t			length;

	length = (arg->flags & FLAG_UNSIGNED
	? itoa_raw(n_to_unsigned(arg), buff, arg)
	: itoa_raw(n_to_signed(arg), buff, arg));
	if (buff[0] == '0')
	{
		if (arg->flags & FLAG_BASE_16)
			arg->flags &= ~FLAG_HASH;
		if (arg->precision == 0)
			length = 0;
		else if (arg->flags & FLAG_BASE_8)
			arg->flags &= ~FLAG_HASH;
	}
	if (arg->flags & FLAG_PRECISION && arg->flags & FLAG_FILL_ZERO)
		arg->flags &= ~FLAG_FILL_ZERO;
	arg->filling = (arg->precision > length) ? arg->precision - length : 0;
	prefixes = get_alt_number_symbols_length(arg->flags);
	arg->padding = (arg->width > (arg->filling + length + prefixes)
	? arg->width - arg->filling - length - prefixes : 0);
	display_arg(arg, buff, length);
	return (length + arg->filling + prefixes + arg->padding);
}

int	format_char(t_arg *arg)
{
	const unsigned char	c = (unsigned char)va_arg(arg->value, int);

	arg->filling = 0;
	arg->padding = (arg->width > 0 ? arg->width - 1 : 0);
	display_arg(arg, (char *)&c, 1);
	return (arg->padding + 1);
}

int	format_float(t_arg *arg)
{
	size_t		len;
	long double	f;
	char		buff[BUFFER_FLOAT_CONVERSION_MAX];

	f = convert_float(arg);
	if (arg->precision > 10)
	{
		arg->filling = arg->precision - 10;
		arg->precision = 10;
	}
	else
		arg->filling = 0;
	len = ftoa(f, buff, arg);
	arg->padding = get_alt_number_symbols_length(arg->flags);
	arg->padding = (arg->width > (arg->filling + len + arg->padding)
	? arg->width - arg->filling - len - arg->padding : 0);
	display_arg(arg, buff, len);
	return (len);
}

int	format_pointer(t_arg *arg)
{
	char				buff[BUFFER_CONVERSION_MAX];
	size_t				length;
	unsigned long long	ptr_val;
	unsigned int		prefix;

	if ((ptr_val = (unsigned long long)va_arg(arg->value, void *)) == 0)
	{
		length = NULL_PTR_SIZE;
		arg->flags &= ~(FLAG_HASH);
		ut_strcat(buff, NULL_PTR_CONTENT);
		prefix = 0;
	}
	else
	{
		length = itoa_raw(ptr_val, buff, arg);
		prefix = get_alt_number_symbols_length(arg->flags);
	}
	arg->flags &= ~(FLAG_SPACE | FLAG_PLUS | FLAG_PRECISION);
	arg->filling = 0;
	arg->padding = ((arg->width > length + prefix)
	? arg->width - length - prefix : 0);
	display_arg(arg, buff, length);
	return (length + arg->padding + prefix);
}
