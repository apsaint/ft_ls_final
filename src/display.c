/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:09:00 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/05 18:58:40 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

int		display_one_by_line(t_flist *f_list, t_options *opt)
{
	unsigned long	ino_w;
	size_t			i;
	if (f_list->count != 0)
	{
		i = 0;
		ino_w = get_max_inode(f_list);
		while (i < f_list->count)
		{
			if (opt->flags & FLAG_DISPLAY_INODE)
				ft_printf("%*llu ", ino_w, f_list->data[i].fstat.st_ino);
			ft_printf("%s\n", f_list->data[i].display_name);
			free(f_list->data[i].path);
			i++;
		}
	}
	return (0);
}

int		display_long_bc(t_flist *f_list, int start, int *items_w,
		t_options *opt)
{
	if (items_w[ITEM_IDX_OWNER] == -1)
	{
		ft_printf("%s  %*d %-*s   %*d, %*d %s %s\n",
			f_list->data[start].modes,
			items_w[ITEM_IDX_NLINKS], f_list->data[start].fstat.st_nlink,
			items_w[ITEM_IDX_GROUP], f_list->data[start].group,
			items_w[ITEM_IDX_MAJOR], major(f_list->data[start].fstat.st_rdev),
			items_w[ITEM_IDX_MINOR], minor(f_list->data[start].fstat.st_rdev),
			f_list->data[start].format_date,
			f_list->data[start].display_name);
	}
	else
	{
		ft_printf("%s  %*d %-*s  %-*s   %*d, %*d %s %s\n",
			f_list->data[start].modes,
			items_w[ITEM_IDX_NLINKS], f_list->data[start].fstat.st_nlink,
			items_w[ITEM_IDX_OWNER], f_list->data[start].owner,
			items_w[ITEM_IDX_GROUP], f_list->data[start].group,
			items_w[ITEM_IDX_MAJOR], major(f_list->data[start].fstat.st_rdev),
			items_w[ITEM_IDX_MINOR], minor(f_list->data[start].fstat.st_rdev),
			f_list->data[start].format_date,
			f_list->data[start].display_name);
	}
	return (0);
}

int		display_long_l(t_flist *f_list, int start, int *items_w,
		t_options *opt)
{
	char	*buf;

	buf = ft_strnew(256);
	readlink(f_list->data[start].path, buf, 256);
	if (items_w[ITEM_IDX_OWNER] == -1)
	{
		ft_printf("%s  %*d %-*s  %*llu %s %s -> %s\n",
			f_list->data[start].modes, items_w[ITEM_IDX_NLINKS],
			f_list->data[start].fstat.st_nlink, items_w[ITEM_IDX_GROUP],
			f_list->data[start].group, items_w[ITEM_IDX_SIZE],
			f_list->data[start].fstat.st_size, f_list->data[start].format_date,
			f_list->data[start].display_name, buf);
	}
	else
	{
		ft_printf("%s  %*d %-*s  %-*s  %*llu %s %s -> %s\n",
			f_list->data[start].modes, items_w[ITEM_IDX_NLINKS],
			f_list->data[start].fstat.st_nlink, items_w[ITEM_IDX_OWNER],
			f_list->data[start].owner, items_w[ITEM_IDX_GROUP],
			f_list->data[start].group, items_w[ITEM_IDX_SIZE],
			f_list->data[start].fstat.st_size, f_list->data[start].format_date,
			f_list->data[start].display_name, buf);
	}
	free(buf);
	return (0);
}

int		display_long_fd(t_flist *f_list, int start, int *items_w,
		t_options *opt)
{
	if (items_w[ITEM_IDX_OWNER] == -1)
	{
		ft_printf("%s  %*d %-*s  %*llu %s %s\n",
			f_list->data[start].modes,
			items_w[ITEM_IDX_NLINKS], f_list->data[start].fstat.st_nlink,
			items_w[ITEM_IDX_GROUP], f_list->data[start].group,
			items_w[ITEM_IDX_SIZE], f_list->data[start].fstat.st_size,
			f_list->data[start].format_date,
			f_list->data[start].display_name);
	}
	else
	{
		ft_printf("%s  %*d %-*s  %-*s  %*llu %s %s\n",
			f_list->data[start].modes,
			items_w[ITEM_IDX_NLINKS], f_list->data[start].fstat.st_nlink,
			items_w[ITEM_IDX_OWNER], f_list->data[start].owner,
			items_w[ITEM_IDX_GROUP], f_list->data[start].group,
			items_w[ITEM_IDX_SIZE], f_list->data[start].fstat.st_size,
			f_list->data[start].format_date,
			f_list->data[start].display_name);
	}
	return (0);
}
