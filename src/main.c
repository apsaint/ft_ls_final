/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:55:04 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/28 23:15:40 by bboutoil         ###   ########.fr       */
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

static int get_stats_from_all(t_path *paths, t_options *opt)
{
	while (paths->path_name != NULL)
	{
		if (*(paths->path_name) == '\0')
		{
			print_path_error("fts_open", ENOENT);
			return (-1);
		}
		paths->err = get_file_stat_by_path(&paths->file_stat, paths->path_name, opt);
		paths++;
	}
	return (0);
	// faire le tri
}


int	get_path_count(t_path *paths)
{
	int count;

	count = 0;
	while (paths->path_name != NULL)
	{
		paths++;
		count++;
	}
	return (count);
}

void catch_path_errors_and_print(t_path *paths, t_path **output)
{
	int size = 0;
	int	i = 0;

	while (paths->path_name != NULL)
	{
		if (paths->err != 0)
		{
			output[size++] = paths;
		}
		paths++;
	}
	while (i < size)
	{
		print_path_error(output[i]->path_name, output[i]->err);
		i++;
	}
}

void catch_files(t_path *paths, t_flist *f_list)
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

void catch_directories_and_run_listing(t_path *paths, t_path **output, int prev_files, t_options *opt)
{
	int size;
	int	i;

	size = 0;
	i = 0;
	while (paths->path_name != NULL)
	{
		if (paths->err == 0)
		{
			if (S_ISDIR(paths->file_stat.fstat.st_mode))
			{
				output[size++] = paths;
			}
		}
		paths++;
	}
	if (prev_files)
		ft_putchar('\n');
	if (size + prev_files > 1)
	{
		while (i < size)
		{
			show_header(output[i]->path_name);
			directory_list(output[i]->path_name, opt);
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			directory_list(output[i]->path_name, opt);
			i++;
		}
	}
}

static int	treat_paths(t_path *paths, t_options *opt)
{
	t_flist			flst;
	t_path 			**tmp;

	if ((tmp = (t_path **)malloc(sizeof(t_path *)
	* (get_path_count(paths) + 1))) == NULL)
		return (-1);
	if (get_stats_from_all(paths, opt) == -1)
		return -1;
	catch_path_errors_and_print(paths, tmp);
	f_list_init(&flst);
	catch_files(paths, &flst);
	if (flst.count != 0)
	{
		f_list_qsort(&flst, opt, flst.count - 1, 0);
		opt->display_func(&flst, opt, paths->path_name);
	}
	catch_directories_and_run_listing(paths, tmp, (flst.count != 0), opt);
	free(tmp);
	// process
	// while (paths->path_name)
	// {
	// 	if (paths->err == 0)
	// 	{
	// 		if (S_ISDIR(paths->file_stat.fstat.st_mode))
	// 		{
	// 			if (show_hd > 0)
	// 				show_header(paths->path_name);
	// 			if(directory_list(paths->path_name, opt) == -1)
	// 				return (-1);
	// 			if ((paths + 1)->path_name != NULL)
	// 				ft_putchar('\n');
	// 		}
	// 		else
	// 		{
	// 			f_list_add(&flst, &paths->file_stat);
	// 		}
	// 	}
	// 	paths++;
	// }
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
