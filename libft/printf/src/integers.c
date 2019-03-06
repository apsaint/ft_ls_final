/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:43:50 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/23 09:49:56 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/types.h>
#include <stdint.h>
#include "ft_printf_internals.h"

/*
** get_base
** ---
** dsc: get base on an integer arg based on its flags
** par: the flags as integer (unsigned int)
** ret: the base as number (unsigned int)
** not: n/a
*/

static unsigned int			get_base(unsigned int flags)
{
	if (flags & FLAG_BASE_8)
		return (8U);
	if (flags & FLAG_BASE_16)
		return (16U);
	if (flags & FLAG_BASE_2)
		return (2U);
	return (10U);
}

/*
** itoa_raw
** ---
** dsc: converts integer to string, add symbols
**      depending on its flags
** par: the number (unsigned long long)
**      the string to output number (unsigned int)
**      the attributes of number (t_arg)
** ret: the length of number in string outputed (size_t)
** not: n/a
*/

size_t						itoa_raw(unsigned long long nb, char *output,
t_arg *arg)
{
	const unsigned int	base = get_base(arg->flags);
	char				*tmp;
	unsigned char		digit;

	tmp = output;
	if (nb == 0)
		*tmp++ = '0';
	while (nb != 0)
	{
		digit = nb % base;
		if (digit < 10)
			*tmp++ = digit + '0';
		else
			*tmp++ = ((arg->flags & FLAG_UPPERCASE) ? 'A' : 'a') + digit - 10;
		nb /= base;
	}
	ut_strnrev(output, tmp - output);
	return ((size_t)(tmp - output));
}

/*
** n_to_unsigned
** ---
** dsc:	convert an arg to unsigned number
** par:	the arg (va_list)
**      the attributes of the arg  (t_arg)
** ret:	the number as unsigned (unsigned long long)
** not:	n/a
*/

unsigned long long			n_to_unsigned(t_arg *arg)
{
	if (arg->flags & FLAG_CHAR)
		return ((unsigned char)va_arg(arg->value, unsigned int));
	if (arg->flags & FLAG_SHORT)
		return ((unsigned short)va_arg(arg->value, unsigned int));
	if (arg->flags & FLAG_LONG)
		return (va_arg(arg->value, unsigned long));
	if (arg->flags & FLAG_LONG_LONG)
		return (va_arg(arg->value, unsigned long long));
	if (arg->flags & FLAG_SIZE_T)
		return (va_arg(arg->value, size_t));
	if (arg->flags & FLAG_INT_MAX)
		return (va_arg(arg->value, uintmax_t));
	return (va_arg(arg->value, unsigned int));
}

/*
** convert_from_arg INTERNAL
** ---
** dsc:	handles properly signed conversion (casting and overflows)
**      to unsigned format needed by itoa printf functions
** par:	the arg (va_list)
**      the attributes of the arg (t_arg)
** ret:	the number as unsigned (unsigned long long)
** not:	required by n_to_signed
*/

static unsigned long long	convert_from_arg(t_arg *arg)
{
	if (arg->flags & FLAG_CHAR)
		return ((char)va_arg(arg->value, int));
	if (arg->flags & FLAG_SHORT)
		return ((short)va_arg(arg->value, int));
	if (arg->flags & FLAG_LONG)
		return (va_arg(arg->value, long));
	if (arg->flags & FLAG_LONG_LONG)
		return (va_arg(arg->value, long long));
	if (arg->flags & FLAG_SIZE_T)
		return (va_arg(arg->value, ssize_t));
	if (arg->flags & FLAG_INT_MAX)
		return (va_arg(arg->value, intmax_t));
	return (va_arg(arg->value, int));
}

/*
** n_to_unsigned
** ---
** dsc:	convert an arg to signed number
** par:	the arg (va_list)
**      the attributes of the arg (t_arg)
** ret:	the number as unsigned (unsigned long long)
** not:	n/a
*/

unsigned long long			n_to_signed(t_arg *arg)
{
	long long res;

	res = convert_from_arg(arg);
	if (res < 0)
		arg->flags |= FLAG_NEGATIVE;
	if (arg->flags & FLAG_CHAR)
		return (res < 0 ? 0 - res : (char)res);
	if (arg->flags & FLAG_SHORT)
		return (res < 0 ? 0 - res : (short)res);
	if (arg->flags & FLAG_LONG)
		return (res < 0 ? 0 - res : (long)res);
	if (arg->flags & FLAG_LONG_LONG)
		return (res < 0 ? 0 - res : (long long)res);
	if (arg->flags & FLAG_INT_MAX)
		return (res < 0 ? 0 - res : (intmax_t)res);
	if (arg->flags & FLAG_SIZE_T)
		return (res < 0 ? 0 - res : (ssize_t)res);
	return (res < 0 ? -res : (int)res);
}
