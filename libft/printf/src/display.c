/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:08:05 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/07 23:04:35 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf_internals.h"

static void		insert_alt_number_symbols(t_arg *arg)
{
	if (arg->flags & FLAG_BASE_8)
		buffer_fill(arg, OCTAL_PREFIX, 1);
	else if (arg->flags & FLAG_BASE_16)
		(arg->flags & FLAG_UPPERCASE ? buffer_fill(arg, HEX_PREFIX_UPPER, 2)
		: buffer_fill(arg, HEX_PREFIX, 2));
	else if (arg->flags & FLAG_BASE_2)
		buffer_fill(arg, BIN_PREFIX, 2);
}

static void		insert_signed_symbols_if_required(t_arg *arg)
{
	if (arg->flags & FLAG_NEGATIVE)
		buffer_fill(arg, CHAR_NEGATIVE, 1);
	else if (arg->flags & FLAG_PLUS)
		buffer_fill(arg, CHAR_POSITIVE, 1);
	else if (arg->flags & FLAG_SPACE)
		buffer_fill(arg, CHAR_SPACE, 1);
}

/*
** insert_padding
** ---
** dsc: insert padding around arg
** par: the arg data (t_arg *)
**      the width of padding
** ret: n/a
** not: the padding representation depends on arg flags.
*/

static void		insert_padding(t_arg *arg, unsigned int padding)
{
	char	pad_char;

	if (padding && !(arg->flags & FLAG_LEFT))
		pad_char = (((arg->flags & FLAG_FILL_ZERO))
		? PADDING_CHAR_ALT : PADDING_CHAR);
	else
		pad_char = PADDING_CHAR;
	while (padding--)
		buffer_fill(arg, &pad_char, 1);
}

/*
** fill_value
** ---
** dsc: fill the arg with default filling char
** par: the arg data (t_arg *)
**      the amount of fill chars (int)
** ret: n/a
** not: fill param is signed.
*/

static void		fill_value(t_arg *arg, int fill)
{
	if (fill <= FILL_TEMPLATE_SIZE)
	{
		buffer_fill(arg, FILL_TEMPLATE, fill);
		return ;
	}
	while (fill > 0)
	{
		fill -= FILL_TEMPLATE_SIZE;
		buffer_fill(arg, FILL_TEMPLATE, FILL_TEMPLATE_SIZE);
	}
	if (fill < 0)
		buffer_fill(arg, FILL_TEMPLATE, -fill);
}

/*
** display_arg
** ---
** dsc: generic function which display an arg depending its
**      attributes
** par: the arg data (t_arg)
**      the pointer to the buff representing the value
**          (const char*)
**      the length of the buff
** ret: n/a
** not: n/a
*/

void			display_arg(t_arg *arg, const char *buff, size_t buff_len)
{
	if ((!(arg->flags & FLAG_LEFT) && !(arg->flags & FLAG_FILL_ZERO)
	&& arg->padding))
		insert_padding(arg, arg->padding);
	if (arg->flags & FLAG_NUMERIC)
	{
		if (arg->flags & FLAG_HASH)
			insert_alt_number_symbols(arg);
		insert_signed_symbols_if_required(arg);
	}
	if (((arg->flags & FLAG_FILL_ZERO) && !(arg->flags & FLAG_LEFT)
	&& arg->padding))
		insert_padding(arg, arg->padding);
	if (!(arg->flags & FLAG_FILL_RIGHT) && arg->filling)
		fill_value(arg, arg->filling);
	if (buff_len != 0)
		buffer_fill(arg, (void *)buff, buff_len);
	if ((arg->flags & FLAG_FILL_RIGHT) && arg->filling)
		fill_value(arg, arg->filling);
	if ((arg->flags & FLAG_LEFT) && arg->padding)
		insert_padding(arg, arg->padding);
}
