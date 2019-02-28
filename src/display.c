/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:09:00 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/28 15:31:45 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

int		param_display_order(t_flist *f_list, t_options *opt, int *start,
		int *end)
{
	if (opt->flags & FLAG_DISPLAY_REVERSE)
	{
		*start = f_list->count - 1;
		*end = -1;
		return (-1);
	}
	*start = 0;
	*end = f_list->count;
	return (1);
}

int		display_one_by_line(t_flist *f_list, t_options *opt, char *path)
{
	int				start;
	int				end;
	const int		inc = param_display_order(f_list, opt, &start, &end);
	unsigned long	ino_w;

	if (opt->flags & FLAG_LIST_SUBDIRS)
		ft_printf("%s:\n", path);
	if (f_list->count != 0)
	{
	
		ino_w = get_max_inode(f_list);
		while (start != end)
		{
			if (opt->flags & FLAG_DISPLAY_INODE)
				ft_printf("%*llu ", ino_w, f_list->data[start].fstat.st_ino);
			ft_printf("%s\n", f_list->data[start].name);
			start += inc;
		}
	}
	return (0);
}

int		display_long_bc(t_flist *f_list, int start, int *items_w)
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
			f_list->data[start].name);
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
			f_list->data[start].name);
	}
	return (0);
}

int		display_long_l(t_flist *f_list, int start, int *items_w)
{
	char	*buf;
	int		size;

	size = f_list->data[start].fstat.st_size;
	if ((buf = (char *)malloc(sizeof(buf) * (size + 1))) == NULL)
		return (-1);
	readlink(f_list->data[start].path, buf, f_list->data[start].fstat.st_size);
	buf[size] = '\0';
	if (items_w[ITEM_IDX_OWNER] == -1)
	{
		ft_printf("%s  %*d %-*s  %*d %s %s -> %s\n",
			f_list->data[start].modes,
			items_w[ITEM_IDX_NLINKS], f_list->data[start].fstat.st_nlink,
			items_w[ITEM_IDX_GROUP], f_list->data[start].group,
			items_w[ITEM_IDX_SIZE], f_list->data[start].fstat.st_size,
			f_list->data[start].format_date,
			f_list->data[start].name, buf);
	}
	else
	{
		ft_printf("%s  %*d %-*s  %-*s  %*d %s %s -> %s\n",
			f_list->data[start].modes,
			items_w[ITEM_IDX_NLINKS], f_list->data[start].fstat.st_nlink,
			items_w[ITEM_IDX_OWNER], f_list->data[start].owner,
			items_w[ITEM_IDX_GROUP], f_list->data[start].group,
			items_w[ITEM_IDX_SIZE], f_list->data[start].fstat.st_size,
			f_list->data[start].format_date,
			f_list->data[start].name, buf);
	}
	free(buf);
	return (0);
}

int		display_long_fd(t_flist *f_list, int start, int *items_w)
{
	if (items_w[ITEM_IDX_OWNER] == -1)
	{
	ft_printf("%s  %*d %-*s  %*d %s %s\n",
			f_list->data[start].modes,
			items_w[ITEM_IDX_NLINKS], f_list->data[start].fstat.st_nlink,
			items_w[ITEM_IDX_GROUP], f_list->data[start].group,
			items_w[ITEM_IDX_SIZE], f_list->data[start].fstat.st_size,
			f_list->data[start].format_date,
			f_list->data[start].name);
	}
	else
	{
		ft_printf("%s  %*d %-*s  %-*s  %*d %s %s\n",
			f_list->data[start].modes,
			items_w[ITEM_IDX_NLINKS], f_list->data[start].fstat.st_nlink,
			items_w[ITEM_IDX_OWNER], f_list->data[start].owner,
			items_w[ITEM_IDX_GROUP], f_list->data[start].group,
			items_w[ITEM_IDX_SIZE], f_list->data[start].fstat.st_size,
			f_list->data[start].format_date,
			f_list->data[start].name);
	}
	return (0);
}
