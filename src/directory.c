/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 21:06:24 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/21 15:14:03 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	directory_list(char *path, t_options *opt)
{
	t_elem elem;
	t_flist flist;
	DIR				*dirp;
	struct	dirent	*dp;

	errno = 0;
	if ((dirp = opendir(path)) == NULL)
	{
		print_path_error(path, "cannot open directory ", errno);
		return (0);
	}
	if (f_list_init(&flist) == ALLOC_ERROR)
		return (-1);
	while ((dp = readdir(dirp)) != NULL)
	{
		ft_strcpy(elem.name, dp->d_name);
		elem.type = dp->d_type;
		stat_t_elem(&elem, dp);
		if (f_list_add(&flist, &elem) == ALLOC_ERROR)
			return (ALLOC_ERROR);
	}
	closedir(dirp);
	display_summary_in_block(&flist, opt);
	f_list_destroy_storage(&flist);
	return (0);
}