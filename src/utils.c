/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:22:33 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/27 15:52:43 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
