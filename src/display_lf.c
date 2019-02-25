/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 13:58:44 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/25 16:22:16 by apsaint-         ###   ########.fr       */
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
// a moove
#define LONG_FORMAT_MAX_ITEMS (8)

enum e_item_index
{
	ITEM_IDX_NLINKS,
	ITEM_IDX_OWNER,
	ITEM_IDX_GROUP,
	ITEM_IDX_SIZE,
	ITEM_IDX_MAJOR,
	ITEM_IDX_MINOR,
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
	return (w);
}

void get_all_items_width(t_flist *f_list, int *items, t_options *opt)
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
		if (items[ITEM_IDX_NLINKS] < f_list->data[i].n_link)
			items[ITEM_IDX_NLINKS] = f_list->data[i].n_link;
		if (f_list->data[i].modes[0] == 'b'
				|| f_list->data[i].modes[0] == 'c')
		{
			if (items[ITEM_IDX_MAJOR] < major(f_list->data[i].dev))
				items[ITEM_IDX_MAJOR] = major(f_list->data[i].dev);
			if (items[ITEM_IDX_MINOR] < minor(f_list->data[i].dev))
				items[ITEM_IDX_MINOR] = minor(f_list->data[i].dev);
			count_bc = 1;
		}
		else
		{
			if (items[ITEM_IDX_SIZE] < f_list->data[i].size)
				items[ITEM_IDX_SIZE] = f_list->data[i].size;
		}
		i++;
	}
	items[ITEM_IDX_MAJOR] = get_width_by_int_item(items[ITEM_IDX_MAJOR]);
	items[ITEM_IDX_MINOR] = 3/*get_width_by_int_item(items[ITEM_IDX_MINOR])*/;
	items[ITEM_IDX_SIZE] = (count_bc > 0) ? (items[ITEM_IDX_MAJOR]
			+ items[ITEM_IDX_MINOR] + 3)
		: get_width_by_int_item(items[ITEM_IDX_SIZE]);
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
		if (f_list->data[start].modes[0] == 'b'
				|| f_list->data[start].modes[0] == 'c')
		{
			ft_printf("%s  %*d %-*s  %-*s   %*d, %*d %s %s\n", 
				f_list->data[start].modes,
				items_w[ITEM_IDX_NLINKS], f_list->data[start].n_link, 
				items_w[ITEM_IDX_OWNER], f_list->data[start].owner,
				items_w[ITEM_IDX_GROUP], f_list->data[start].group,
				items_w[ITEM_IDX_MAJOR], major(f_list->data[start].dev),
				items_w[ITEM_IDX_MINOR], minor(f_list->data[start].dev),
				f_list->data[start].format_date,
				f_list->data[start].name);
		}
		else if (f_list->data[start].modes[0] == 'l')
		{
			char *buf;
			int size = f_list->data[start].size;
			buf = (char *)malloc(sizeof(buf) * (size + 1));
				//return (-1);
			readlink(f_list->data[start].path, buf, f_list->data[start].size);
			buf[size] = '\0';
			ft_printf("%s  %*d %-*s  %-*s  %*d %s %s -> %s\n", 
				f_list->data[start].modes,
				items_w[ITEM_IDX_NLINKS], f_list->data[start].n_link, 
				items_w[ITEM_IDX_OWNER], f_list->data[start].owner,
				items_w[ITEM_IDX_GROUP], f_list->data[start].group,
				items_w[ITEM_IDX_SIZE], f_list->data[start].size,
				f_list->data[start].format_date,
				f_list->data[start].name, buf);
			free(buf);
		}
		else
		{
			ft_printf("%s  %*d %-*s  %-*s  %*d %s %s\n", 
				f_list->data[start].modes,
				items_w[ITEM_IDX_NLINKS], f_list->data[start].n_link, 
				items_w[ITEM_IDX_OWNER], f_list->data[start].owner,
				items_w[ITEM_IDX_GROUP], f_list->data[start].group,
				items_w[ITEM_IDX_SIZE], f_list->data[start].size,
				f_list->data[start].format_date,
				f_list->data[start].name);
		}
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
