/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:13:34 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/06 08:44:26 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void	f_list_reverse(t_flist *f_list)
{
	int	cur;
	int	end;

	cur = 0;
	end = f_list->count - 1;
	while (cur < end)
		swap(&f_list->data[cur++], &f_list->data[end--]);
}
