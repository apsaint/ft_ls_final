/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:19:03 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/07 18:24:48 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PRINTF_BUFFER_SIZE (64)
# define PRINTF_OUTPUT_ERROR (-1)

/*
** ft_printf
** ---
** dsc: print formatted string to standard output.
** par: the string to format (const char *)
**      optional arguments (...)
** ret: the number of printed chars
** not: -1 is return when an output error is encountered
*/

int	ft_printf(const char *format, ...);

#endif
