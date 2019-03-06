/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:55:04 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/06 12:06:49 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char const *av[])
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
