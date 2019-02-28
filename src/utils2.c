/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 09:22:12 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/28 11:08:46 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_type_file(t_fstat *fs, struct dirent *dp)
{
	if (dp->d_type == DT_DIR)
		ft_strcat(fs->name, "/");
	else if (dp->d_type == DT_LNK)
		ft_strcat(fs->name, "@");
	else if (dp->d_type == DT_FIFO)
		ft_strcat(fs->name, "|");
	else if (fs->fstat.st_mode & S_IXUSR)
		ft_strcat(fs->name, "*");
	else if (dp->d_type == DT_SOCK)
		ft_strcat(fs->name, "=");
	else if (dp->d_type == DT_WHT)
		ft_strcat(fs->name, "%");
}
