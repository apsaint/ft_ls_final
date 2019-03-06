/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:40:11 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/19 16:51:03 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_printf_internals.h"

/*
** print_until_find_arg_or_end_of_string INTERNAL
** dsc: see name
** par: the arg data (t_arg *)
** ret: the number of char printed (int)
** not: n/a
*/

static int	print_until_find_arg_or_end_of_string(t_arg *arg)
{
	const char	*tmp = arg->raw_input;
	const char	*begin = tmp;

	while (*tmp && *tmp != SYM_SPECIFIER)
		tmp++;
	if (tmp != arg->raw_input)
	{
		buffer_fill(arg, (void *)arg->raw_input, tmp - arg->raw_input);
		arg->raw_input = tmp;
	}
	return (tmp - begin);
}

/*
** parse_arg INTERNAL FUNC
** ---
** dsc: parse an arg to evaluate its attributes
** par: the arg data (t_arg *)
**      the pointer to a format function (t_format_func)
** ret:	1 on success, 0 on failure (error or fake arg) (int)
** not:	n/a
*/

static int	parse_arg(t_arg *arg, t_format_func *func)
{
	const char	*undo = arg->raw_input++;

	arg->flags = 0;
	arg->precision = 0;
	eval_arg_flags(arg);
	eval_arg_numerics(arg);
	eval_arg_length(arg);
	eval_arg_specifier(arg, func);
	if (arg->flags & FLAG_ERROR)
	{
		arg->raw_input = (char *)undo;
		return (0);
	}
	if ((arg->flags & FLAG_FILL_ZERO) && (arg->flags & FLAG_LEFT))
		arg->flags &= ~FLAG_FILL_ZERO;
	return (1);
}

/*
** process INTERNAL FUNC
** ---
** dsc: process format of the string
** par: the pointer to the source string (const char*)
**      the list of varadic args (va_list)
** ret: the number of printed characters (int)
** not: n/a
*/

static int	process(t_arg *arg)
{
	t_format_func	format;
	int				len;

	len = 0;
	while (*arg->raw_input)
	{
		len += print_until_find_arg_or_end_of_string(arg);
		if (*arg->raw_input == SYM_SPECIFIER)
		{
			if (parse_arg(arg, &format))
				len += format(arg);
			else
			{
				buffer_fill(arg, (void *)arg->raw_input++, 1);
				len++;
			}
		}
	}
	buffer_flush(arg);
	return ((arg->flags & FLAG_OUTPUT_ERROR ? -1 : len));
}

/*
** ft_printf
** ---
** dsc: write formatted output to stdout
** par: the pointer to the source string (const char*)
**      the list of varadic args (va_list)
** ret: the number of printed characters  (int)
** not: n/a
*/

int			ft_printf(const char *format, ...)
{
	t_arg	arg;
	int		res;
	char	buff[PRINTF_BUFFER_SIZE];

	arg.buffer = buff;
	arg.raw_input = format;
	arg.buff_len = 0;
	va_start(arg.value, format);
	res = process(&arg);
	va_end(arg.value);
	return (res);
}
