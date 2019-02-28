/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:14:35 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/28 23:07:20 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>

static void	format_modes(mode_t m, t_fstat *file)
{
	if (S_ISDIR(m))
		file->modes[0] = 'd';
	else if (S_ISCHR(m))
		file->modes[0] = 'c';
	else if (S_ISBLK(m))
		file->modes[0] = 'b';
	else if (S_ISFIFO(m))
		file->modes[0] = 'p';
	else if (S_ISLNK(m))
		file->modes[0] = 'l';
	else
		file->modes[0] = '-';
	file->modes[1] = (m & S_IRUSR) ? 'r' : '-';
	file->modes[2] = (m & S_IWUSR) ? 'w' : '-';
	file->modes[3] = (m & S_IXUSR) ? 'x' : '-';
	file->modes[4] = (m & S_IRGRP) ? 'r' : '-';
	file->modes[5] = (m & S_IWGRP) ? 'w' : '-';
	file->modes[6] = (m & S_IXGRP) ? 'x' : '-';
	file->modes[7] = (m & S_IROTH) ? 'r' : '-';
	file->modes[8] = (m & S_IWOTH) ? 'w' : '-';
	file->modes[9] = (m & S_IXOTH) ? 'x' : '-';
	file->modes[10] = '\0';
}

/*
 * rempli les elements de la structure utilisant stat
 */

void		get_file_stat(t_fstat *file, struct dirent *dp, char *path, t_options *opt)
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
	file->fstat = stat_elem;
	format_modes(stat_elem.st_mode, file);
	if (opt->flags & FLAG_F)
		add_type_file(file, dp);
	pw = getpwuid(stat_elem.st_uid);
	gp = getgrgid(stat_elem.st_gid);
	if (pw == NULL || pw->pw_name == NULL)
		ls_itoa_min(stat_elem.st_uid, file->owner);
	else
		ft_strcpy(file->owner, pw->pw_name);
	if (gp->gr_name == NULL)
		ls_itoa_min(stat_elem.st_gid, file->group);
	else
		ft_strcpy(file->group, gp->gr_name);
	format_date(file->format_date, ctime(&stat_elem.st_mtime),
			stat_elem.st_mtime);
}


//TODO: Les deux fonctions sont quasiment identique, il faut remedier a cela
// autant n utiliser que la version avec le path seul, donc le combine doit
// se faire en amont.


int		get_file_stat_by_path(t_fstat *file, char *path, t_options *opt)
{
	struct stat		stat_elem;
	struct passwd	*pw;
	struct group	*gp;
	char			name[4097];
	const size_t	len = ft_strlen(path);
	ft_bzero(name, 4097);
	// a virer
	strcpy(file->name, path);
	file->path = ft_strdup(path);
	errno = 0;
	if (path[len - 1] != '/' && opt->display_func == &display_long_format)
		lstat(path, &stat_elem);
	else
		stat(path, &stat_elem);
	if (errno != 0)
		return (errno);
	file->fstat = stat_elem;
	format_modes(stat_elem.st_mode, file);
	pw = getpwuid(stat_elem.st_uid);
	gp = getgrgid(stat_elem.st_gid);
	if (pw == NULL || pw->pw_name == NULL)
		ls_itoa_min(stat_elem.st_uid, file->owner);
	else
		ft_strcpy(file->owner, pw->pw_name);
	if (gp->gr_name == NULL)
		ls_itoa_min(stat_elem.st_gid, file->group);
	else
		ft_strcpy(file->group, gp->gr_name);
	format_date(file->format_date, ctime(&stat_elem.st_mtime),
			stat_elem.st_mtime);
	return (0);
}