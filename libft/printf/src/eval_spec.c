/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:46:55 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/15 21:19:51 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internals.h"

static void	eval_integer_specifier(t_arg *arg, t_format_func *form_func)
{
	arg->flags |= FLAG_NUMERIC;
	if (!(arg->flags & FLAG_PRECISION))
		arg->precision = 1;
	if (*arg->raw_input == SPEC_HEX || *arg->raw_input == SPEC_HEX_UPPER)
	{
		arg->flags |= FLAG_BASE_16 | FLAG_UNSIGNED;
		if (*arg->raw_input == SPEC_HEX_UPPER)
			arg->flags |= FLAG_UPPERCASE;
	}
	else if (*arg->raw_input == SPEC_OCTAL)
		arg->flags |= (FLAG_BASE_8 | FLAG_UNSIGNED);
	else if (*arg->raw_input == SPEC_BIN)
		arg->flags |= (FLAG_BASE_2 | FLAG_UNSIGNED);
	else
	{
		arg->flags |= FLAG_BASE_10;
		if (*arg->raw_input == 'u')
			arg->flags |= FLAG_UNSIGNED;
	}
	if ((arg->flags & FLAG_UNSIGNED))
		arg->flags &= ~(FLAG_SPACE | FLAG_PLUS);
	*form_func = &format_integer;
}

/*
** arg_eval_specifier
** ---
** dsc:	eval arg specifier
** par:	the pointer to the source string (const char*)
**      the data arg infos (va_list)
**      the pointer to a format function(t_format_func)
** ret: void
** not: n/a
*/

void		eval_arg_specifier(t_arg *arg, t_format_func *form_func)
{
	if (specifier_is_integer(*arg->raw_input))
		eval_integer_specifier(arg, form_func);
	else if (*arg->raw_input == SPEC_STRING)
		*form_func = &format_string;
	else if (*arg->raw_input == SPEC_CHAR)
		*form_func = &format_char;
	else if (*arg->raw_input == SPEC_FLOAT)
	{
		arg->flags |= FLAG_NUMERIC | FLAG_FLOAT | FLAG_FILL_RIGHT;
		if (!(arg->flags & FLAG_PRECISION))
			arg->precision = FLOAT_DEFAULT_PRECISION;
		*form_func = &format_float;
	}
	else if (*arg->raw_input == SPEC_PERCENT)
		*form_func = &format_percent;
	else if (*arg->raw_input == SPEC_PTR)
	{
		arg->flags |= (FLAG_NUMERIC | FLAG_BASE_16 | FLAG_HASH);
		*form_func = format_pointer;
	}
	else
		arg->flags |= FLAG_ERROR;
	arg->raw_input++;
}
