/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:29:32 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/11 10:27:21 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "ft_printf_internals.h"

void		buffer_flush(t_arg *arg)
{
	if (write(STDOUT_FILENO, arg->buffer, arg->buff_len) == -1)
		arg->flags |= FLAG_OUTPUT_ERROR;
	arg->buff_len = 0;
}

void		buffer_fill(t_arg *arg, void *src, size_t len)
{
	const char *tmp = (char *)src;

	while (len != 0 && arg->buff_len < PRINTF_BUFFER_SIZE)
	{
		len--;
		arg->buffer[arg->buff_len++] = *tmp++;
	}
	if (arg->buff_len == PRINTF_BUFFER_SIZE)
	{
		buffer_flush(arg);
		if (len != 0)
			buffer_fill(arg, (void *)tmp, len);
	}
}
