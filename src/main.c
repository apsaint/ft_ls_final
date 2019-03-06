/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:55:04 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/06 09:00:38 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	catch_path_errors_and_print(t_path *paths, t_path **output,
		t_options *opt)
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
	while (i < size)
	{
		print_path_error(output[i]->path_name, output[i]->err, opt);
		free(output[i++]->file_stat.path);
	}
	return (i);
}

static void	catch_files(t_path *paths, t_flist *f_list, t_options *opt)
{
	while (paths->path_name != NULL)
	{
		if (paths->err == 0)
		{
			if (!S_ISDIR(paths->file_stat.fstat.st_mode)
			|| opt->flags & FLAG_TREAT_AS_FILE)
				f_list_add(f_list, &paths->file_stat);
		}
		paths++;
	}
}

static int	check_error_dir(t_path *paths, t_path **output, t_options *opt)
{
	int size;

	size = 0;
	while (paths->path_name != NULL)
	{
		if (paths->err == 0)
		{
			if (S_ISDIR(paths->file_stat.fstat.st_mode))
			{
				if (paths->file_stat.modes[3] != 'x')
					opt->flags |= FLAG_NO_READ;
				output[size++] = paths;
			}
		}
		paths++;
	}
	return (size);
}

static void	catch_directories_and_run_listing(t_path *paths, t_path **output,
int prev_files, t_options *opt)
{
	int	size;
	int	i;
	int	show_dir;

	size = check_error_dir(paths, output, opt);
	i = 0;
	if (prev_files && size > 0)
		ft_putchar('\n');
	show_dir = (size + prev_files > 1);
	while (i < size)
	{
		if (i != 0)
			ft_putchar('\n');
		directory_list(output[i]->path_name, opt, show_dir);
		free(output[i++]->file_stat.path);
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
	error_qsort(paths, get_path_count(paths) - 1, 0);
	n_errors = catch_path_errors_and_print(paths, tmp, opt);
	f_list_init(&flst);
	catch_files(paths, &flst, opt);
	if (flst.count != 0)
	{
		f_list_qsort(&flst, opt, flst.count - 1, 0);
		opt->flags |= FLAG_HIDE_TOTAL;
		opt->display_func(&flst, opt);
	}
	if (!(opt->flags & FLAG_TREAT_AS_FILE))
		catch_directories_and_run_listing(paths, tmp,
		((flst.count + n_errors) > 0), opt);
	f_list_destroy_storage(&flst);
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
	return ((opt.flags & FLAG_MINOR_ERROR) ? EXIT_FAILURE : EXIT_SUCCESS);
}
