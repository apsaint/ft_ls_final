/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 21:06:24 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/22 15:52:44 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

static int collect_special_dots_if_required(DIR *dir, t_options *opt, t_flist *f_list, char *path)
{
	t_fstat		fs;
	struct		dirent *d;
	const int	dots_count = 2;
	int	i;

	i = 0;
	while (i++ < dots_count)
	{
		if ((d = readdir(dir)) == NULL)
			return (0); 
		if (opt->flags & FLAG_SHOW_MAP_DIR)
		{
			fs.type = d->d_type;
			ft_strcpy(fs.name, d->d_name);
			stat_t_elem(&fs, d, path);
			if (f_list_add(f_list, &fs) == ALLOC_ERROR)
				return (ALLOC_ERROR);
		}
	}
	return (0);
}

static int collect_files(DIR *dir, t_options *opt, t_flist *f_list, char *path)
{
	t_fstat fs;
	struct	dirent	*dp;

	if (collect_special_dots_if_required(dir, opt, f_list, path) == ALLOC_ERROR)
		return (ALLOC_ERROR);
	while ((dp = readdir(dir)) != NULL)
	{
		if ((!(opt->flags & FLAG_SHOW_HIDDEN_FILE)) && dp->d_name[0] == '.')
			continue ;
		ft_strcpy(fs.name, dp->d_name);
		fs.type = dp->d_type;
		stat_t_elem(&fs, dp, path);
		if (f_list_add(f_list, &fs) == ALLOC_ERROR)
			return (ALLOC_ERROR);
	}
	return (0);
}

static int	try_list_subdirs(char *path, t_flist *f_list, t_options *opt)
{
	char	new_path[4096];
	size_t	i;

	i = 0;
	ft_bzero(new_path, sizeof(new_path));
	while (i < f_list->count)
	{
		if (f_list->data[i].type == 4) // a modif
		{
			if (ft_strcmp(f_list->data[i].name, ".") == 0
			|| ft_strcmp(f_list->data[i].name, "..") == 0)
			{
				i++;
				continue;
			}
			combine_paths(path, f_list->data[i].name, new_path);
			directory_list(new_path, opt);
			ft_bzero(new_path, sizeof(new_path));
		}
		i++;
	}
	return (0);
}

int	directory_list(char *path, t_options *opt)
{
	t_flist f_list;
	DIR				*dirp;

	errno = 0;
	if ((dirp = opendir(path)) == NULL)
	{
		print_path_error(path, "cannot open directory ", errno);
		return (0);
	}
	if (f_list_init(&f_list) == ALLOC_ERROR)
		return (ALLOC_ERROR);
	if (collect_files(dirp, opt, &f_list, path) == ALLOC_ERROR)
		return (ALLOC_ERROR);
	closedir(dirp);
	opt->display_func(&f_list, opt, path);
	if (opt->flags & FLAG_LIST_SUBDIRS)
		try_list_subdirs(path, &f_list, opt);
	f_list_destroy_storage(&f_list);
	return (0);
}
