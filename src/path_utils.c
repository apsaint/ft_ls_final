/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:51:17 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/06 12:11:08 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		combine_paths(char *path1, char *path2, char *output)
{
	const	int s = ft_strlen(path1);

	ft_strlcat(output, path1, 4097);
	if (*(path1 + s - 1) == '/')
		ft_strlcat(output, path2, 4097);
	else
	{
		ft_strlcat(output, "/", 4097);
		ft_strlcat(output, path2, 4097);
	}
	return (0);
}

void	set_file_name(t_fstat *file, char *name, t_options *opt)
{
	const mode_t m = file->fstat.st_mode;

	ft_strcpy(file->name, name);
	if (opt->flags & FLAG_COLORIZE)
	{
		if (S_ISDIR(m))
			ft_strcpy(file->display_name, CBLU);
		else if (S_ISCHR(m))
			ft_strcpy(file->display_name, CYEL);
		else if (S_ISBLK(m))
			ft_strcpy(file->display_name, CMAG);
		else if (S_ISFIFO(m))
			ft_strcpy(file->display_name, CCYN);
		else if (S_ISLNK(m))
			ft_strcpy(file->display_name, CGRN);
		else if ((m & S_IXUSR) || (m & S_IXGRP) || (m & S_IXOTH))
			ft_strcpy(file->display_name, CRED);
		else
			ft_strcpy(file->display_name, CWHT);
	}
	else
		ft_strcpy(file->display_name, CWHT);
	ft_strcat(file->display_name, file->name);
	ft_strcat(file->display_name, CWHT);
}
