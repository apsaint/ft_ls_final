/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:09:00 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/21 15:11:54 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_printf.h"

int	display_summary_in_block(t_flist *f_list, t_options *opt)
{
	int i;

	i = 0;
	if (opt->flags & FLAG_LIST_SUBDIRS)
	{
		// ajouter le header
	}
	while (i < (int)f_list->count)
	{
		printf("%s\n", f_list->data[i++].name);
	}
	return (0);
}