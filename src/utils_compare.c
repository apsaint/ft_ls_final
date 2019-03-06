/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_compare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 08:42:31 by apsaint-          #+#    #+#             */
/*   Updated: 2019/03/06 08:45:08 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		compare_by_ascii(t_fstat *f1, t_fstat *f2)
{
	return ((ft_strcmp(f1->name, f2->name) > 0 ? 1 : -1));
}

int		compare_by_size(t_fstat *f1, t_fstat *f2)
{
	if (f1->fstat.st_size < f2->fstat.st_size)
		return (1);
	else if (f1->fstat.st_size == f2->fstat.st_size)
		return (compare_by_ascii(f1, f2));
	else
		return (-1);
}

int		compare_by_date(t_fstat *f1, t_fstat *f2)
{
	if (f1->fstat.st_mtime < f2->fstat.st_mtime)
		return (1);
	else if (f1->fstat.st_mtime == f2->fstat.st_mtime)
		return (compare_by_ascii(f1, f2));
	else
		return (-1);
}
