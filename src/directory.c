/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 21:06:24 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/21 21:28:59 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <unistd.h>

static int collect_special_dots_if_required(DIR *dir, t_options *opt, t_flist *f_list, t_elem *el)
{
	struct dirent *d;
	const int	dots_count = 2;
	int	i;

	i = 0;
	while (i++ < dots_count)
	{
		if ((d = readdir(dir)) == NULL)
			return (0);
		if (opt->flags & FLAG_SHOW_MAP_DIR)
		{
			el->type = d->d_type;
			ft_strcpy(el->name, d->d_name);
			stat_t_elem(el, d);
			if (f_list_add(f_list, el) == ALLOC_ERROR)
				return (ALLOC_ERROR);
		}
	}
	return (0);
}

static int collect_files(DIR *dir, t_options *opt, t_flist *f_list)
{
	t_elem elem;
	struct	dirent	*dp;

	if (collect_special_dots_if_required(dir, opt, f_list, &elem) == ALLOC_ERROR)
		return (ALLOC_ERROR);
	while ((dp = readdir(dir)) != NULL)
	{
		if ((!(opt->flags & FLAG_SHOW_HIDDEN_FILE)) && dp->d_name[0] == '.')
			continue ;
		ft_strcpy(elem.name, dp->d_name);
		elem.type = dp->d_type;
		stat_t_elem(&elem, dp);
		if (f_list_add(f_list, &elem) == ALLOC_ERROR)
			return (ALLOC_ERROR);
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
	if (collect_files(dirp, opt, &f_list) == ALLOC_ERROR)
		return (ALLOC_ERROR);
	closedir(dirp);
	opt->display_func(&f_list, opt, path);
	f_list_destroy_storage(&f_list);
	return (0);
}