/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:55:04 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/04 08:53:04 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_ls.h"
#include <ft_printf.h>

static int	catch_path_errors_and_print(t_path *paths, t_path **output)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (paths->path_name != NULL)
	{
		if (paths->err != 0)
			output[size++] = paths;
		paths++;
	}
	error_qsort(*output, size - 1, 0);
	while (i < size)
	{
		print_path_error(output[i]->path_name, output[i]->err);
		i++;
	}
	return (i);
}

static void	catch_files(t_path *paths, t_flist *f_list)
{
	while (paths->path_name != NULL)
	{
		if (paths->err == 0)
		{
			if (!S_ISDIR(paths->file_stat.fstat.st_mode))
				f_list_add(f_list, &paths->file_stat);
		}
		paths++;
	}
}

static void	catch_directories_and_run_listing(t_path *paths, t_path **output,
int prev_files, t_options *opt)
{
	int	size;
	int	i;
	int	show_dir;

	size = 0;
	i = 0;
	while (paths->path_name != NULL)
	{
		if (paths->err == 0)
		{
			if (S_ISDIR(paths->file_stat.fstat.st_mode))
				output[size++] = paths;
		}
		paths++;
	}
	if (prev_files && size > 0)
		ft_putchar('\n');
	show_dir = (size + prev_files > 1);
	while (i < size)
	{
		if (i != 0)
			ft_putchar('\n');
		directory_list(output[i++]->path_name, opt, show_dir);
	}
}

static int	treat_paths(t_path *paths, t_options *opt)
{
	t_flist			flst;
	t_path			**tmp;
	int				n_errors;

	if ((tmp = (t_path **)malloc(sizeof(t_path *)
	* (get_path_count(paths) + 1))) == NULL)
		return (-1);
	if (get_stats_from_all_paths(paths, opt) == -1)
		return (-1);
	n_errors = catch_path_errors_and_print(paths, tmp);
	f_list_init(&flst);
	catch_files(paths, &flst);
	if (flst.count != 0)
	{
		f_list_qsort(&flst, opt, flst.count - 1, 0);
		opt->flags |= FLAG_HIDE_TOTAL;
		opt->display_func(&flst, opt);
	}
	catch_directories_and_run_listing(paths, tmp, ((flst.count + n_errors) > 0),
	opt);
	free(tmp);
	return (0);
}

int			main(int ac, char const *av[])
{
	t_options	opt;
	t_path		*paths;

	opt.flags = 0;
	opt.display_func = &display_one_by_line;
	opt.sort_func = &compare_by_ascii;
	paths = NULL;
	if (ac > 1)
	{
		if (param_eval_all(av + 1, ac - 1, &opt, &paths) == -1)
			return (EXIT_FAILURE);
	}
	if (paths == NULL || paths->path_name == NULL)
		directory_list(".", &opt, 0);
	else
		treat_paths(paths, &opt);
	free(paths);
	return (EXIT_SUCCESS);
}
