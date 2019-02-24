/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:58:44 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/24 15:14:41 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

int		total_block(t_flist *f_list)
{
	size_t	i;
	int		total;

	total = 0;
	i = 0;
	while (i < f_list->count)
	{
		total += f_list->data[i].n_block;
		i++;
	}
	return (total);
}

#define LONG_FORMAT_MAX_ITEMS (6)

enum e_item_index
{
	ITEM_IDX_NLINKS,
	ITEM_IDX_OWNER,
	ITEM_IDX_GROUP,
	ITEM_IDX_SIZE,
	ITEM_IDX_LAST_MOD,
	ITEM_IDX_PATH_NAME
};

int		get_width_by_int_item(int item)
{
	int w;

	w = 1;
	while (item > 9)
	{
		item /= 10;
		w++;
	}
	return (w + 2);
}

void get_all_items_width(t_flist *f_list, int *items, t_options *opt)
{
	register int	w;
	size_t			i;

	i = 0;

	while (i < f_list->count)
	{
		if (items[ITEM_IDX_OWNER] < (w = (int)ft_strlen(f_list->data[i].owner)))
			items[ITEM_IDX_OWNER] = w + 1;
		if (items[ITEM_IDX_GROUP] < (w = (int)ft_strlen(f_list->data[i].group)))
			items[ITEM_IDX_GROUP] = w + 1;
		if (items[ITEM_IDX_NLINKS] < f_list->data[i].n_link)
			items[ITEM_IDX_NLINKS] = f_list->data[i].n_link;
		if (items[ITEM_IDX_SIZE] < f_list->data[i].size)
			items[ITEM_IDX_SIZE] = f_list->data[i].size;
		i++;
	}
	items[ITEM_IDX_SIZE] = get_width_by_int_item(items[ITEM_IDX_SIZE]);
	items[ITEM_IDX_NLINKS] = get_width_by_int_item(items[ITEM_IDX_NLINKS]);
}

void	display_items(t_flist *f_list, t_options *opt)
{
	int			start;
	int			end;
	const int	inc = param_display_order(f_list, opt, &start, &end);
	int	items_w[LONG_FORMAT_MAX_ITEMS];
	ft_bzero(items_w, sizeof(items_w));

	get_all_items_width(f_list, items_w, opt);
	while (start != end)
	{
		ft_printf("%s%*d%*s%*s%*d %s%3d %02d:%02d %s\n", 
			f_list->data[start].modes,
			items_w[ITEM_IDX_NLINKS], f_list->data[start].n_link, 
			items_w[ITEM_IDX_OWNER], f_list->data[start].owner,
			items_w[ITEM_IDX_GROUP], f_list->data[start].group,
			items_w[ITEM_IDX_SIZE], f_list->data[start].size,
			(f_list->data[start].date_modif).month, 
			(f_list->data[start].date_modif).day,
			(f_list->data[start].date_modif).hour,
			(f_list->data[start].date_modif).min,
			f_list->data[start].name);
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