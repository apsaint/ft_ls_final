/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 10:52:48 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/23 09:49:56 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf_internals.h"

/*
** get_decimal_part INTERNAL
** ---
** dsc: get decimal part of a floating number
** par: the number (long double)
**      the precision to select size of part (unsigned int)
** ret: the decimal part as unsigned (unsigned long long)
** not: n/a
*/

size_t						fill_fract_zero(char *output, long double n,
unsigned int prec)
{
	size_t	len;

	len = 0;
	if (prec > 10)
		prec = 10;
	else if (prec == 0)
		return (0);
	n = (n - (long long)n);
	while (n < 0.1)
	{
		*output++ = '0';
		n *= 10;
		len++;
	}
	return (len);
}

static unsigned long long	get_decimal_part(long double n, unsigned int prec)
{
	unsigned long long	res;

	if (prec > 10)
		prec = 10;
	else if (prec == 0)
		return (0);
	n = (n - (long long)n);
	prec++;
	while (prec--)
		n *= 10;
	res = (unsigned long long)n;
	if (res % 10 >= 5)
		return ((res + 5) / 10);
	return (res / 10);
}

/*
** convert_float
** ---
** dsc: convert an arg of type float to a long double
**      and stock some attributes of the number.
** par: the arg (va_list)
**      the attributes of the arg (t_arg)
** ret: the arg as floating number (long double)
** not: n/a
*/

long double					convert_float(t_arg *arg)
{
	long double res;

	if (arg->flags & FLAG_LONG_DOUBLE)
		res = va_arg(arg->value, long double);
	else
		res = va_arg(arg->value, double);
	if (res < 0)
	{
		arg->flags |= FLAG_NEGATIVE;
		res *= -1;
	}
	return (res);
}

/*
** ftoa
** ---
** dsc:	format a floatting number into a string
** par:	the number								(long double)
** 		the string to store the number			(char *)
** 		the attributes of the number 			(t_arg)
** ret:	the size of the number into the string	(size_t)
** not:	n/a
*/

size_t						ftoa(long double n, char *output, t_arg *arg)
{
	size_t				len;
	unsigned long long	nb;
	unsigned int		prec;

	nb = get_decimal_part(n, arg->precision);
	len = nb != 0 ? itoa_min(nb, output) : 0;
	if (len == 0 && arg->precision != 0)
	{
		prec = arg->precision;
		while (prec--)
			output[len++] = '0';
	}
	else
		len += fill_fract_zero(&output[len], n, arg->precision);
	if (len != 0 || (arg->flags & FLAG_HASH))
		output[len++] = '.';
	nb = (unsigned long long)n;
	len += itoa_min(nb, output + len);
	ut_strnrev(output, len);
	return (len);
}
