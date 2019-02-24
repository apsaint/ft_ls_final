/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:09:00 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/24 20:06:19 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

int		param_display_order(t_flist *f_list, t_options *opt, int *start, int *end)
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
	int			start;
	int			end;
	const int	inc = param_display_order(f_list, opt, &start, &end);

	if (opt->flags & FLAG_LIST_SUBDIRS)
		printf("%s:\n", path);
	if (f_list->count == 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (start != end)
	{
		printf("%s\n", f_list->data[start].name);
		start += inc;
	}
	return (0);
}
