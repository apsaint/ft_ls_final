/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:55:04 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/28 11:12:39 by bboutoil         ###   ########.fr       */
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
	// faire le tri
}

static int	treat_paths(t_path *paths, t_options *opt)
{
	const t_path	*beg = paths;
	int				show_hd;
	
	if (get_stats_from_all(paths) == -1)
		return -1;
	while (paths->path_name != NULL)
	{
		if (paths->err != 0)
			print_path_error(paths->path_name, paths->err);
		paths++;
	}
	if (paths->path_name != NULL)
		show_hd = ((paths + 1)->path_name != NULL ? 1 : 0);
	else
		show_hd = 0;
	paths = (t_path *)beg;
	while (paths->path_name)
	{
		if (paths->err == 0)
		{
			if (show_hd == 1)
				show_header(paths->path_name);
			if(directory_list(paths->path_name, opt) == -1)
				return (-1);
			if ((paths + 1)->path_name != NULL)
				ft_putchar('\n');
		}
		paths++;
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
	// while (*paths != NULL)
	// 	paths++;
	// show_hd = ((paths - 1) != p_begin ? 1 : 0);
	// paths = p_begin;
	// while (*paths != NULL)
	// {
	// 	if (show_hd == 1)
	// 		show_header(*paths);
	// 	if (directory_list(*paths, &opt) == -1)
	// 		break;
	// 	if (*(paths + 1) != NULL)
	// 		ft_putchar('\n');
	// 	paths++;
	// }
	free(paths);
	return (EXIT_SUCCESS);
}
