/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:52:20 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/23 09:50:27 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdarg.h>

size_t			ut_strlen(const char *s)
{
	const char	*begin = s;

	while (*s)
		s++;
	return (s - begin);
}

size_t			ut_strnlen(const char *s, size_t max_len)
{
	const char	*begin = s;

	while (*s && max_len-- != 0)
		s++;
	return (s - begin);
}

void			ut_strnrev(char *s, size_t size)
{
	char	*end;

	if (size == 0)
		return ;
	end = s + size - 1;
	while (s < end)
	{
		*s ^= *end;
		*end ^= *s;
		*s++ ^= *end--;
	}
}

void			ut_strcat(char *dst, const char *src)
{
	while ((*dst++ = *src++))
		;
}

unsigned int	parse_wildchar(va_list va)
{
	int	val;

	return (((val = va_arg(va, int)) < 0 ? 0 : val));
}
