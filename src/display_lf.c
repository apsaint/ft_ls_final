/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:58:44 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/27 14:35:48 by apsaint-         ###   ########.fr       */
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
		if (items[ITEM_IDX_SIZE] < f_list->data[i].size)
			items[ITEM_IDX_SIZE] = f_list->data[i].size;
		return (0);
	}
}

void	get_all_items_width(t_flist *f_list, int *items, t_options *opt)
{
	register int	w;
	size_t			i;
	int				count_bc;

	i = 0;
	while (i < f_list->count)
	{
		if (items[ITEM_IDX_OWNER] < (w = (int)ft_strlen(f_list->data[i].owner)))
			items[ITEM_IDX_OWNER] = w;
		if (items[ITEM_IDX_GROUP] < (w = (int)ft_strlen(f_list->data[i].group)))
			items[ITEM_IDX_GROUP] = w;
		if (items[ITEM_IDX_NLINKS] < f_list->data[i].n_link)
			items[ITEM_IDX_NLINKS] = f_list->data[i].n_link;
		count_bc = item_index_size(f_list, i, items);
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
	get_all_items_width(f_list, items_w, opt);
	while (start != end)
	{
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
	ft_printf("total %d\n", total_block(f_list));
	display_items(f_list, opt);
	return (0);
}
