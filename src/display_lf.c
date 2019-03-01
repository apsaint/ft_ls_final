/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:58:44 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/28 16:37:22 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

int		item_index_size(t_flist *f_list, int i, int *items)
{
	if (f_list->data[i].modes[0] == 'b'
			|| f_list->data[i].modes[0] == 'c')
	{
		items[ITEM_IDX_MAJOR] = 2;
		items[ITEM_IDX_MINOR] = 3;
		return (1);
	}
	else
	{
		if (items[ITEM_IDX_SIZE] < f_list->data[i].fstat.st_size)
			items[ITEM_IDX_SIZE] = f_list->data[i].fstat.st_size;
		return (0);
	}
}

long	get_max_inode(t_flist *f_list)
{
	unsigned long	max;
	size_t			i;

	max = 0;
	i = 0;
	while (i < f_list->count)
	{
		if (max < f_list->data[i].fstat.st_ino)
			max = f_list->data[i].fstat.st_ino;
		i++;
	}
	return (get_width_by_int_item(max));
}

void	get_all_items_width(t_flist *f_list, int *items)
{
	register int	w;
	size_t			i;
	int				count_bc;

	i = 0;
	count_bc = 0;
	while (i < f_list->count)
	{
		if (items[ITEM_IDX_OWNER] < (w = (int)ft_strlen(f_list->data[i].owner)))
			items[ITEM_IDX_OWNER] = w;
		if (items[ITEM_IDX_GROUP] < (w = (int)ft_strlen(f_list->data[i].group)))
			items[ITEM_IDX_GROUP] = w;
		if (items[ITEM_IDX_NLINKS] < f_list->data[i].fstat.st_nlink)
			items[ITEM_IDX_NLINKS] = f_list->data[i].fstat.st_nlink;
		count_bc += item_index_size(f_list, i, items);
		i++;
	}
	items[ITEM_IDX_SIZE] = (count_bc > 0) ? (items[ITEM_IDX_MAJOR] + 6)
		: get_width_by_int_item(items[ITEM_IDX_SIZE]);
	items[ITEM_IDX_NLINKS] = get_width_by_int_item(items[ITEM_IDX_NLINKS]);
}

void	display_items(t_flist *f_list, t_options *opt)
{
	int			start;
	int			end;
	const int	inc = param_display_order(f_list, opt, &start, &end);
	int			items_w[LONG_FORMAT_MAX_ITEMS];

	ft_bzero(items_w, sizeof(items_w));
	get_all_items_width(f_list, items_w);
	if (opt->flags & FLAG_DISPLAY_INODE)
		items_w[ITEM_IDX_INO] = get_max_inode(f_list);
	if (opt->flags & FLAG_LONG_G)
		items_w[ITEM_IDX_OWNER] = -1;
	while (start != end)
	{
		if (opt->flags & FLAG_DISPLAY_INODE)
			ft_printf("%*d ", items_w[ITEM_IDX_INO],
					f_list->data[start].fstat.st_ino);
		if (f_list->data[start].modes[0] == 'b'
				|| f_list->data[start].modes[0] == 'c')
			display_long_bc(f_list, start, items_w);
		else if (f_list->data[start].modes[0] == 'l')
			display_long_l(f_list, start, items_w);
		else
			display_long_fd(f_list, start, items_w);
		start += inc;
	}
}

int		display_long_format(t_flist *f_list, t_options *opt, char *path)
{
	if (opt->flags & FLAG_LIST_SUBDIRS)
		printf("%s:\n", path);
	if (f_list->count != 0)
	{
		ft_printf("total %d\n", total_block(f_list));
		display_items(f_list, opt);
	}
	return (0);
}
