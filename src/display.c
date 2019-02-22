/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:09:00 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/22 22:22:51 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

static void	param_display_order(t_flist *f_list, t_options *opt, int *start, int *end, int *inc)
{
	if (opt->flags & FLAG_DISPLAY_REVERSE)
	{
		*inc = -1;
		*start = f_list->count - 1;
		*end = -1;
	}
	else
	{
		*inc = 1;
		*start = 0;
		*end = f_list->count;
	}
}

int	display_one_by_line(t_flist *f_list, t_options *opt, char *path)
{
	int	start;
	int	end;
	int	inc;

	if (opt->flags & FLAG_LIST_SUBDIRS)
		printf("%s:\n", path);
	if (f_list->count == 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	param_display_order(f_list, opt, &start, &end, &inc);
	while (start != end)
	{
		printf("%s\n", f_list->data[start].name);
		start += inc;
	}
	return (0);
}


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

int		max_width_int(t_flist *f_list, int start, int end, int inc, int opt)
{
	int		w;
	int		max;

	max = 0;
	w = 1;
	while (start != end)
	{
		if (opt == 1)
		{
			if (max < f_list->data[start].n_link)
				max = f_list->data[start].n_link;
		}
		else if (opt == 2)
		{
			if (max < f_list->data[start].size)
				max = f_list->data[start].size;
		}
		start += inc;
	}
	while (max > 9)
	{
		max /= 10;
		w++;
	}
	return (w + 2);
}

int		max_width_str(t_flist *f_list, int start, int end, int inc, int opt)
{
	int		max;

	max = 0;
	while (start != end)
	{
		if (opt == 1)
		{
			if (max < (int)ft_strlen(f_list->data[start].owner))
				max = (int)ft_strlen(f_list->data[start].owner);
		}
		else if (opt == 2)
		{
			if (max < (int)ft_strlen(f_list->data[start].group))
				max = (int)ft_strlen(f_list->data[start].group);
		}
		start += inc;
	}
	return (max + 1);
}

void	display_final(t_flist *f_list, int start, int end, int inc)
{
	int		max_link;
	int		max_ow;
	int		max_gp;
	int		max_sz;

	max_link = max_width_int(f_list, start, end, inc, 1);
	max_sz = max_width_int(f_list, start, end, inc, 2);
	max_ow = max_width_str(f_list, start, end, inc, 1);
	max_gp = max_width_str(f_list, start, end, inc, 2);
	while (start != end)
	{
		ft_printf("%s%*d%*s%*s%*d %s%3d %02d:%02d %s\n", f_list->data[start].modes, max_link,
				f_list->data[start].n_link, max_ow, f_list->data[start].owner,
				max_gp, f_list->data[start].group, max_sz,
				f_list->data[start].size,
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
	int		start;
	int		end;
	int		inc;

	if (opt->flags & FLAG_LIST_SUBDIRS)
		printf("%s:\n", path);
	param_display_order(f_list, opt, &start, &end, &inc);
	ft_printf("total %d\n", total_block(f_list));
	display_final(f_list, start, end, inc);
	return (0);
}
