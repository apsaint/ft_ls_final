/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:55:04 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/27 20:49:44 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_ls.h"
#include <ft_printf.h>

static void	show_header(char *path)
{
	ft_putstr(path);
	ft_putstr(":\n");
}

int main(int ac, char const *av[])
{
	t_options	opt;
	char		**paths;
	char		**p_begin;
	int			show_hd;

	opt.flags = 0;
	opt.display_func = &display_one_by_line;
	opt.sort_func = &compare_by_ascii;
	paths = NULL;
	if (ac > 1)
	{
		if (param_eval_all(av+1, ac-1, &opt, &paths) == -1)
			return (EXIT_SUCCESS);
	}
	if (paths == NULL || *paths == NULL)
		return (directory_list(".", &opt));
	p_begin = paths;
	while (*paths != NULL)
		paths++;
	show_hd = ((paths - 1) != p_begin ? 1 : 0);
	paths = p_begin;
	while (*paths != NULL)
	{
		if (show_hd == 1)
			show_header(*paths);
		if (directory_list(*paths, &opt) == -1)
			break;
		if (*(paths + 1) != NULL)
			ft_putchar('\n');
		paths++;
	}
	free(p_begin);
	return (EXIT_SUCCESS);
}
