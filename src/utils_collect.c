/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:17:17 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/06 12:18:50 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		collect_mapping_files(DIR *dir, t_options *opt,
		t_flist *f_list, char *path)
{
	t_fstat			fs;
	struct dirent	*d;
	const int		dots_count = 2;
	int				i;

	i = 0;
	while (i++ < dots_count)
	{
		if ((d = readdir(dir)) == NULL)
			return (0);
		if (opt->flags & FLAG_SHOW_MAP_DIR)
		{
			fs.type = d->d_type;
			get_file_stat(&fs, d, path, opt);
			if (f_list_add(f_list, &fs) == ALLOC_ERROR)
				return (ALLOC_ERROR);
		}
	}
	return (0);
}

int		collect_files(DIR *dir, t_options *opt, t_flist *f_list, char *path)
{
	t_fstat			fs;
	struct dirent	*dp;

	if (collect_mapping_files(dir, opt, f_list, path) == ALLOC_ERROR)
		return (ALLOC_ERROR);
	while ((dp = readdir(dir)) != NULL)
	{
		if ((!(opt->flags & FLAG_SHOW_HIDDEN_FILE)) && dp->d_name[0] == '.')
			continue ;
		fs.type = dp->d_type;
		get_file_stat(&fs, dp, path, opt);
		if (f_list_add(f_list, &fs) == ALLOC_ERROR)
			return (ALLOC_ERROR);
	}
	return (0);
}
