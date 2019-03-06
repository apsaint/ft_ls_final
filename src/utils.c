/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:22:33 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/06 08:29:20 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	ls_itoa_min(unsigned long long nb, char *output)
{
	char *tmp;

	tmp = output;
	if (nb == 0)
		*tmp++ = '0';
	while (nb != 0)
	{
		*tmp++ = ((nb % 10) + '0');
		nb /= 10;
	}
	*tmp = '\0';
	return ((size_t)(tmp - output));
}

void	swap(t_fstat *f1, t_fstat *f2)
{
	t_fstat tmp;

	tmp = *f1;
	*f1 = *f2;
	*f2 = tmp;
}

void	swap_str(t_path *s1, t_path *s2)
{
	t_path tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int		get_width_by_int_item(int item)
{
	int w;

	w = 1;
	while (item > 9)
	{
		item /= 10;
		w++;
	}
	return (w);
}

int		total_block(t_flist *f_list)
{
	size_t	i;
	int		total;

	total = 0;
	i = 0;
	while (i < f_list->count)
	{
		total += f_list->data[i].fstat.st_blocks;
		i++;
	}
	return (total);
}
