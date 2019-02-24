/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:14:35 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/24 21:47:15 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>

/*
 * rempli les elements de la structure utilisant stat
 */

void	get_file_stat(t_fstat *file, struct dirent *dp, char *path)
{
	struct stat		stat_elem;
	struct passwd	*pw;
	struct group	*gp;
	char			name[4097];

	ft_bzero(name, 4097);
	combine_paths(path, dp->d_name, name);
	file->path = ft_strdup(name);
	if (file->type == 10)
		lstat(file->path, &stat_elem);
	else
		stat(file->path, &stat_elem);
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
	file->mod_time = stat_elem.st_mtime;
	format_date(file->format_date, ctime(&stat_elem.st_mtime), stat_elem.st_mtime);
}
