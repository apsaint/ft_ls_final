/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:14:35 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/22 13:26:24 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* TODO verifier l utilisation de birthdate
 * */

size_t			ls_itoa_min(unsigned long long nb, char *output)
{
	char *tmp;

	tmp = output;
	if (nb == 0)
		*tmp++ = '0';
	while (nb != 0)
	{
		*tmp++ = ((nb % 10) + '0');
		nb /= 10;
	}
	return ((size_t)(tmp - output));
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

void	stat_t_elem(t_fstat *file, struct dirent *dp, char *path)
{
	struct stat		stat_elem;
	struct passwd	*pw;
	struct group	*gp;

	if (file->type == 10)
		lstat(path, &stat_elem);
	else
		stat(path, &stat_elem);
	file->n_link = stat_elem.st_nlink;
	file->size = stat_elem.st_size;
	file->n_block = stat_elem.st_blocks;
	create_mode_str(stat_elem.st_mode, file);
	pw = getpwuid(stat_elem.st_uid); 	
	gp = getgrgid(stat_elem.st_gid);
	if (pw->pw_name == NULL)
		ls_itoa_min(pw->pw_uid, file->owner);
	else
		ft_strcpy(file->owner, pw->pw_name);
	if (gp->gr_name == NULL)
		ls_itoa_min(gp->gr_gid, file->group);
	else
		ft_strcpy(file->group, gp->gr_name);
	(file->date_modif).mod_timestamp = stat_elem.st_mtime;
	time_t_elem(&file->date_modif, ctime(&stat_elem.st_mtime));
	// time_t_elem(&elem->date_crea, ctime(&stat_elem.st_birthtime));
}
