/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:14:35 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/21 13:38:33 by apsaint-         ###   ########.fr       */
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

void	time_t_elem(t_telem *telem, char	*time)
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

/* rempli les elements de la structure utilisant stat
 */
void	stat_t_elem(t_elem *elem, struct dirent *dp)
{
	struct stat		stat_elem;
	struct passwd	*pw;
	struct group	*gp;

	stat(dp->d_name, &stat_elem);
	elem->n_link = stat_elem.st_nlink;
	elem->size = stat_elem.st_size;
	pw = getpwuid(stat_elem.st_uid);
	gp = getgrgid(stat_elem.st_gid);
	ft_strcpy(elem->owner, pw->pw_name);
	ft_strcpy(elem->group, gp->gr_name);
	(elem->date_modif).mod_timestamp = stat_elem.st_mtime;
	time_t_elem(&elem->date_modif, ctime(&stat_elem.st_mtime));
	time_t_elem(&elem->date_crea, ctime(&stat_elem.st_birthtime));
}

/* Gestion du remplissage de la structure 
 */
void	fill_t_elem(char *path, t_elem *elem)
{
	DIR				*dirp;
	struct	dirent	*dp;

	dirp = opendir(path);
	while ((dp = readdir(dirp)) != NULL)
	{
		ft_strcpy(elem->name, dp->d_name);
		elem->type = dp->d_type;
		stat_t_elem(elem, dp);
	}
	closedir(dirp);
}
