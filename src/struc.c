/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:14:35 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/21 15:38:55 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* TODO verifier l utilisation de birthdate
 * */

int		convert_year(char **time)
{
	int		y;
	int		i;

	y = 0;
	i = 3;
	(*time)++;
	while (i > 0)
		y += (*((*time)++) - '0') * ft_pow(10, i--);
	y += *((*time)++) - '0';
	return (y);
}

int		convert_time(char **time)
{
	int		t;

	t = 0;
	(*time)++;
	if (**time != '0')
		t = (**time - '0') * 10;
	(*time)++;
	t += *((*time)++) - '0';
	return (t);
}

void	time_t_elem(t_telem *telem, char *time)
{
	int		i;
	int		day;

	i = 0;
	day = 0;
	while (*time != ' ')
		time++;
	time++;
	while (*time != ' ')
		telem->month[i++] = *time++;
	telem->month[i] = '\0';
	time++;
	if (*(time + 1) != ' ')
		day = (*time++ - '0') * 10;
	day += *time++ - '0';
	telem->day = day;
	telem->hour = convert_time(&time);
	telem->min = convert_time(&time);
	telem->sec = convert_time(&time);
	telem->year = convert_year(&time);
}

/*
 * rempli les elements de la structure utilisant stat
 */

void	stat_t_elem(t_elem *elem, struct dirent *dp)
{
	struct stat		stat_elem;
	struct passwd	*pw;
	struct group	*gp;

	if (elem->type == 10)
		lstat(dp->d_name, &stat_elem);
	else
		stat(dp->d_name, &stat_elem);
	elem->n_link = stat_elem.st_nlink;
	elem->size = stat_elem.st_size;
	create_mode_str(stat_elem.st_mode, elem);
	pw = getpwuid(stat_elem.st_uid);
	gp = getgrgid(stat_elem.st_gid);
	if (pw->pw_name == NULL)
		ft_strcpy(elem->owner, pw->pw_uid);
	else
		ft_strcpy(elem->owner, pw->pw_name);
	if (gp->gr_name == NULL)
		ft_strcpy(elem->owner, gp->gr_gid);
	else
		ft_strcpy(elem->group, gp->gr_name);
	(elem->date_modif).mod_timestamp = stat_elem.st_mtime;
	time_t_elem(&elem->date_modif, ctime(&stat_elem.st_mtime));
	// time_t_elem(&elem->date_crea, ctime(&stat_elem.st_birthtime));
}
