/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numerics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:48:28 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/08 18:13:14 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf_internals.h"

/*
** atoi_min
** ---
** dsc:	minimalist atoi
** par:	the pointer to the source string	(const char*)
** ret:	the number							(unsigned int)
** not:	n/a
*/

unsigned int	atoi_min(const char **str)
{
	int	res;

	res = 0;
	if (**str == '-')
		return (0);
	while (**str >= '0' && **str <= '9')
		res = res * 10U + (*((*str)++) - '0');
	return (res);
}

/*
** itoa_min
** ---
** dsc:	minimalist itoa
** par:	the number as unsigned							(unsigned long long)
** ret:	the size of the number into the output string	(char *)
** not:	n/a
*/

size_t			itoa_min(unsigned long long nb, char *output)
{
	char *tmp;

	tmp = output;
	if (nb == 0)
		*tmp++ = '0';
	while (nb != 0)
	{
		*tmp++ = ((nb % 10) + '0');
		nb /= 10;
	}
	return ((size_t)(tmp - output));
}

/*
** specifier_is_integer
** ---
** dsc: check if specifier is from integer type
** par: the specifier (const char)
** ret: 1 on success, 0 on failure
** not: n/a
*/

int				specifier_is_integer(const char spec)
{
	const char *template = SPEC_INTEGERS;

	while (*template)
	{
		if (*template++ == spec)
			return (1);
	}
	return (0);
}

unsigned int	get_alt_number_symbols_length(unsigned int flags)
{
	unsigned int	len;

	len = 0;
	if (flags & FLAG_HASH)
	{
		if ((flags & FLAG_BASE_8))
			len += 1;
		else if (flags & FLAG_BASE_16)
			len += 2;
		else if (flags & FLAG_BASE_2)
			len += 2;
	}
	if (flags & FLAG_NEGATIVE)
		len += 1;
	else if (flags & FLAG_PLUS || flags & FLAG_SPACE)
		len += 1;
	return (len);
}
