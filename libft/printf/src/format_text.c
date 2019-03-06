/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:16:08 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/23 09:49:22 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internals.h"

int	format_string(t_arg *arg)
{
	const char		*str = va_arg(arg->value, char *);
	size_t			len;

	arg->padding = 0;
	arg->filling = 0;
	if (str == NULL)
	{
		buffer_fill(arg, NULL_STRING_CONTENT, NULL_STRING_SIZE);
		return (NULL_STRING_SIZE);
	}
	len = (arg->flags & FLAG_PRECISION
	? ut_strnlen(str, arg->precision) : ut_strlen(str));
	arg->padding = (arg->width > len ? arg->width - len : 0);
	display_arg(arg, str, len);
	return (len + arg->padding);
}

int	format_percent(t_arg *arg)
{
	arg->filling = 0;
	arg->padding = 0;
	display_arg(arg, "%", 1);
	return (1);
}
