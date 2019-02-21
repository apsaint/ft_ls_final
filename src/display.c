/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:09:00 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/21 20:51:30 by bboutoil         ###   ########.fr       */
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

int	display_summary_in_block(t_flist *f_list, t_options *opt)
{
	int	start;
	int	end;
	int	inc;

	param_display_order(f_list, opt, &start, &end, &inc);
	if (opt->flags & FLAG_LIST_SUBDIRS)
	{
		// ajouter le header
	}
	while (start != end)
	{
		printf("%s\n", f_list->data[start].name);
		start += inc;
	}
	return (0);
}