/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:21:56 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/02 13:00:14 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

int	get_stats_from_all_paths(t_path *paths, t_options *opt)
{
	while (paths->path_name != NULL)
	{
		if (*(paths->path_name) == '\0')
		{
			print_path_error("fts_open", ENOENT, opt);
			return (-1);
		}
		paths->err = get_file_stat_by_path(&paths->file_stat,
		paths->path_name, opt);
		paths++;
	}
	return (0);
}
