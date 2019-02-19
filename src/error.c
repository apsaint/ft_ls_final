/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:07:57 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/19 17:24:21 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "ft_ls.h"
#include"libft.h"

// TODO: Impl semble merdique, a test, et voir si y a pas plus
// simple a faire.
int	show_error(char *prefix, char *err, unsigned int err_type)
{
	char	str[256];
	size_t	len;

	len = ft_strlcat(str, prefix, sizeof(str));
	len += ft_strlcat(str, prefix + len, sizeof(str));

	return(write(STDERR_FILENO, str, len));
}