/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:13:34 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/27 09:20:38 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		compare_by_ascii(t_fstat *f1, t_fstat *f2)
{
	return ((ft_strcmp(f1->name, f2->name) > 0 ? 1 : -1));
}

int		compare_by_size(t_fstat *f1, t_fstat *f2)
{
	if (f1->size < f2->size)
		return (1);
	else if (f1->size == f2->size)
		return (compare_by_ascii(f1, f2));
	else
		return (-1);
}

int		compare_by_date(t_fstat *f1, t_fstat *f2)
{
	if (f1->mod_time < f2->mod_time)
		return (1);
	else if (f1->mod_time == f2->mod_time)
		return (compare_by_ascii(f1, f2));
	else
		return (-1);
}

int		partition(t_flist *f_list, int min, int max, t_options *opt)
{
	int			i;
	int			j;
	t_fstat		pivot;

	i = min - 1;
	j = min;
	pivot = f_list->data[max];
	while (j <= (max - 1))
	{
		if (opt->sort_func(&f_list->data[j], &pivot) == -1)
		{
			i++;
			swap(&f_list->data[i], &f_list->data[j]);
		}
		j++;
	}
	swap(&f_list->data[i + 1], &f_list->data[max]);
	return (i + 1);
}

void	f_list_qsort(t_flist *f_list, t_options *opt, int max, int min)
{
	int part;

	if (min < max)
	{
		part = partition(f_list, min, max, opt);
		f_list_qsort(f_list, opt, part - 1, min);
		f_list_qsort(f_list, opt, max, part + 1);
	}
}