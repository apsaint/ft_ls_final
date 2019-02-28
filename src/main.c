/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:55:04 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/28 14:02:19 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_ls.h"
#include <ft_printf.h>

static void	show_header(char *path)
{
	ft_putstr(path);
	ft_putstr(":\n");
}

// static void	sort_paths(t_path *paths)
// {
// 	const t_path	*begin = paths;
// 	int				is_sorted;

// 	is_sorted = 0;
// 	while (is_sorted = 0)
// 	{
// 		is_sorted = 1;
// 		paths = begin;
// 		while (paths->path_name != NULL)
// 		{
// 			if (S_ISDIR(paths->file_stat.fstat.st_mode))
// 			paths++;
// 		}
// 	}
// }

static int get_stats_from_all(t_path *paths)
{
	while (paths->path_name != NULL)
	{
		if (*(paths->path_name) == '\0')
		{
			print_path_error("fts_open", ENOENT);
			return (-1);
		}
		paths->err = get_file_stat_by_path(&paths->file_stat, paths->path_name);
		paths++;
	}
	return (0);
	// faire le tri
}

static int	treat_paths(t_path *paths, t_options *opt)
{
	const t_path	*beg = paths;
	int				show_hd;
	t_flist			flst;

	show_hd = -1;
	if (get_stats_from_all(paths) == -1)
		return -1;
	// error handling (a moove ailleurs surement)
	while (paths->path_name != NULL)
	{
		if (paths->err != 0)
			print_path_error(paths->path_name, paths->err);
		else
			show_hd++;
		paths++;
	}
	paths = (t_path *)beg;
	// process
	f_list_init(&flst);
	while (paths->path_name)
	{
		if (paths->err == 0)
		{
			if (S_ISDIR(paths->file_stat.fstat.st_mode))
			{
				if (show_hd > 0)
					show_header(paths->path_name);
				if(directory_list(paths->path_name, opt) == -1)
					return (-1);
				if ((paths + 1)->path_name != NULL)
					ft_putchar('\n');
			}
			else
			{
				f_list_add(&flst, &paths->file_stat);
			}
		}
		paths++;
	}
	if (flst.count != 0)
	{
		f_list_qsort(&flst, opt, flst.count - 1, 0);
		opt->display_func(&flst, opt, paths->path_name);
	}
	return (0);
}

int main(int ac, char const *av[])
{
	t_options	opt;
	t_path		*paths;

	opt.flags = 0;
	opt.display_func = &display_one_by_line;
	opt.sort_func = &compare_by_ascii;
	paths = NULL;
	if (ac > 1)
	{
		if (param_eval_all(av+1, ac-1, &opt, &paths) == -1)
			return (EXIT_FAILURE);
	}
	if (paths == NULL || paths->path_name == NULL)
		directory_list(".", &opt);
	else
		treat_paths(paths, &opt);
	free(paths);
	return (EXIT_SUCCESS);
}
