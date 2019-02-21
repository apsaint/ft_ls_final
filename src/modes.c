/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_modes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:26:07 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/21 14:46:35 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	get_elem_type(mode_t m)
{
	if (S_ISDIR(m))
		return ('d');
	else if (S_ISCHR(m))
		return ('c');
	else if (S_ISBLK(m))
		return ('b');
	else if (S_ISFIFO(m))
		return ('p');
	else if (S_ISLNK(m))
		return ('l');
	else
		return ('-');
}

void	get_mode_user(mode_t m, char *modes)
{
	if (m & S_IRUSR)
		modes[1] = 'r';
	else
		modes[1] = '-';
	if (m & S_IWUSR)
		modes[2] = 'w';
	else
		modes[2] = '-';
	if (m & S_IXUSR)
		modes[3] = 'x';
	else
		modes[3] = '-';
}

void	get_mode_group(mode_t m, char *modes)
{
	if (m & S_IRGRP)
		modes[4] = 'r';
	else
		modes[4] = '-';
	if (m & S_IWGRP)
		modes[5] = 'w';
	else
		modes[5] = '-';
	if (m & S_IXGRP)
		modes[6] = 'x';
	else
		modes[6] = '-';
}

void	get_mode_other(mode_t m, char *modes)
{
	if (m & S_IROTH)
		modes[7] = 'r';
	else
		modes[7] = '-';
	if (m & S_IWOTH)
		modes[8] = 'w';
	else
		modes[8] = '-';
	if (m & S_IXOTH)
		modes[9] = 'x';
	else
		modes[9] = '-';
}

void	create_mode_str(mode_t m, t_elem *elem)
{
	elem->modes[0] = get_elem_type(m);
	get_mode_user(m, elem->modes);
	get_mode_group(m, elem->modes);
	get_mode_other(m, elem->modes);
	elem->modes[10] = '\0';
}
