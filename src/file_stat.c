/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:14:35 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/06 08:31:06 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	add_type_file(t_fstat *fs, struct dirent *dp)
{
	if (dp->d_type == DT_DIR)
		ft_strcat(fs->display_name, "/");
	else if (dp->d_type == DT_LNK)
		ft_strcat(fs->display_name, "@");
	else if (dp->d_type == DT_FIFO)
		ft_strcat(fs->name, "|");
	else if (fs->fstat.st_mode & S_IXUSR)
		ft_strcat(fs->display_name, "*");
	else if (dp->d_type == DT_SOCK)
		ft_strcat(fs->display_name, "=");
	else if (dp->d_type == DT_WHT)
		ft_strcat(fs->display_name, "%");
}

void		set_file_name(t_fstat *file, char *name, t_options *opt)
{
	const mode_t	m = file->fstat.st_mode;

	ft_strcpy(file->name, name);
	if (opt->flags & FLAG_COLORIZE)
	{
		if (S_ISDIR(m))
			ft_strcpy(file->display_name, CBLU);
		else if (S_ISCHR(m))
			ft_strcpy(file->display_name, CYEL);
		else if (S_ISBLK(m))
			ft_strcpy(file->display_name, CMAG);
		else if (S_ISFIFO(m))
			ft_strcpy(file->display_name, CCYN);
		else if (S_ISLNK(m))
			ft_strcpy(file->display_name, CGRN);
		else if ((m & S_IXUSR) || (m & S_IXGRP) || (m & S_IXOTH))
			ft_strcpy(file->display_name, CRED);
		else
			ft_strcpy(file->display_name, CWHT);
	}
	else
		ft_strcpy(file->display_name, CWHT);
	ft_strcat(file->display_name, file->name);
	ft_strcat(file->display_name, CWHT);
}

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
	file->modes[3] = get_permission_uid(m, ((m & S_IXUSR) ? 'x' : '-'));
	file->modes[4] = (m & S_IRGRP) ? 'r' : '-';
	file->modes[5] = (m & S_IWGRP) ? 'w' : '-';
	file->modes[6] = get_permission_gid(m, ((m & S_IXGRP) ? 'x' : '-'));
	file->modes[7] = (m & S_IROTH) ? 'r' : '-';
	file->modes[8] = (m & S_IWOTH) ? 'w' : '-';
	file->modes[9] = get_permission_sticky(m, ((m & S_IXOTH) ? 'x' : '-'));
	file->modes[10] = '\0';
}

static void	get_file_stat_common(t_fstat *file, struct stat *stat_elem)
{
	struct passwd	*pw;
	struct group	*gp;

	pw = getpwuid(stat_elem->st_uid);
	gp = getgrgid(stat_elem->st_gid);
	if (pw == NULL || pw->pw_name == NULL)
		ls_itoa_min(stat_elem->st_uid, file->owner);
	else
		ft_strcpy(file->owner, pw->pw_name);
	if (gp == NULL || gp->gr_name == NULL)
		ls_itoa_min(stat_elem->st_gid, file->group);
	else
		ft_strcpy(file->group, gp->gr_name);
	format_date(file->format_date, ctime(&stat_elem->st_mtime),
			stat_elem->st_mtime);
}

void		get_file_stat(t_fstat *file, struct dirent *dp,
char *path, t_options *opt)
{
	struct stat		stat_elem;
	char			name[4097];

	ft_bzero(name, 4097);
	combine_paths(path, dp->d_name, name);
	file->path = ft_strdup(name);
	if (file->type == 10)
		lstat(file->path, &stat_elem);
	else
		stat(file->path, &stat_elem);
	file->fstat = stat_elem;
	set_file_name(file, dp->d_name, opt);
	format_modes(stat_elem.st_mode, file);
	if (opt->flags & FLAG_F)
		add_type_file(file, dp);
	get_file_stat_common(file, &stat_elem);
}

int			get_file_stat_by_path(t_fstat *file, char *path, t_options *opt)
{
	struct stat		stat_elem;
	char			name[4097];
	const size_t	len = ft_strlen(path);

	ft_bzero(name, 4097);
	file->path = ft_strdup(path);
	errno = 0;
	if (path[len - 1] != '/' && opt->display_func == &display_long_format)
		lstat(path, &stat_elem);
	else
		stat(path, &stat_elem);
	if (errno != 0)
		return (errno);
	file->fstat = stat_elem;
	set_file_name(file, path, opt);
	format_modes(stat_elem.st_mode, file);
	get_file_stat_common(file, &stat_elem);
	return (0);
}
