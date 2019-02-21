/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:55:04 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/21 19:41:17 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_ls.h"
#include <ft_printf.h>

int main(int ac, char const *av[])
{
	t_options	opt;
	char		**paths;
	char		**p_begin;

	opt.flags = 0;
	paths = NULL;
	if (ac > 1)
	{
		if (param_eval_all(av+1, ac-1, &opt, &paths) == -1)
			return (0);
	}
	if (paths == NULL || *paths == NULL)
		return (directory_list(".", &opt));
	p_begin = paths;
	while (*paths != NULL)
	{
		if (directory_list(*paths, &opt) == -1)
			break;
		paths++;
	}
	free(p_begin);
	return (0);
}
