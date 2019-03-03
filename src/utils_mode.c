/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 10:35:57 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/03 10:39:16 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	get_permission_sticky(mode_t m, char c)
{
	if (m & S_ISVTX)
		return ((c == 'x') ? 't' : 'T');
	else
		return (c);
}

char	get_permission_uid(mode_t m, char c)
{
	if (m & S_ISUID)
		return ((c == 'x') ? 's' : 'S');
	else
		return (c);
}

char	get_permission_gid(mode_t m, char c)
{
	if (m & S_ISGID)
		return ((c == 'x') ? 's' : 'S');
	else
		return (c);
}
