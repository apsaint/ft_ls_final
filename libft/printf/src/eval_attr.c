/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:18:37 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/15 21:19:52 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internals.h"

/*
** arg_eval_flags
** ---
** dsc: eval arg flags
** par: the pointer to arg data struc (t_arg *)
** ret: void
** not: precision and width are included.
*/

void		eval_arg_flags(t_arg *arg)
{
	while (*arg->raw_input)
	{
		if (*arg->raw_input == ATTR_HASH)
			arg->flags |= FLAG_HASH;
		else if (*arg->raw_input == ATTR_ZERO)
			arg->flags |= FLAG_FILL_ZERO;
		else if (*arg->raw_input == ATTR_MINUS)
			arg->flags |= FLAG_LEFT;
		else if (*arg->raw_input == ATTR_PLUS)
			arg->flags |= FLAG_PLUS;
		else if (*arg->raw_input == ATTR_SPACE)
			arg->flags |= FLAG_SPACE;
		else
			break ;
		arg->raw_input++;
	}
}

void		eval_arg_numerics(t_arg *arg)
{
	if (*arg->raw_input == SYM_WILDCHAR)
	{
		arg->raw_input++;
		arg->width = parse_wildchar(arg->value);
	}
	else
		arg->width = atoi_min(&arg->raw_input);
	if (*arg->raw_input == SYM_PRECISION)
	{
		arg->raw_input++;
		if (*arg->raw_input == SYM_WILDCHAR)
		{
			arg->raw_input++;
			arg->precision = parse_wildchar(arg->value);
		}
		else
			arg->precision = atoi_min(&arg->raw_input);
		arg->flags |= FLAG_PRECISION;
	}
}

/*
** eval_arg_modifier
** ---
** dsc: eval arg modifier
** par: the pointer to arg data struc (t_arg *)
** ret: void
** not: n/a
*/

void		eval_arg_length_extended(t_arg *arg)
{
	if (*arg->raw_input == 'j')
		arg->flags |= FLAG_INT_MAX;
	else if (*arg->raw_input == 'z')
		arg->flags |= FLAG_SIZE_T;
	else
		return ;
	arg->raw_input++;
}

void		eval_arg_length(t_arg *arg)
{
	if (*arg->raw_input == 'h')
	{
		if (*(arg->raw_input + 1) == 'h')
		{
			arg->flags |= FLAG_CHAR;
			arg->raw_input = arg->raw_input + 2;
			return ;
		}
		arg->flags |= FLAG_SHORT;
	}
	else if (*arg->raw_input == 'l')
	{
		if (*(arg->raw_input + 1) == 'l')
		{
			arg->flags |= FLAG_LONG_LONG;
			arg->raw_input = arg->raw_input + 2;
			return ;
		}
		arg->flags |= FLAG_LONG;
	}
	else if (*arg->raw_input == 'L')
		arg->flags |= FLAG_LONG_DOUBLE;
	else
		return (eval_arg_length_extended(arg));
	arg->raw_input++;
}
