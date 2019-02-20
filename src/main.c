/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:55:04 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/19 21:46:55 by bboutoil         ###   ########.fr       */
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

	paths = NULL;
	if (ac > 1)
	{
		if (param_eval_all(av+1, ac-1, &opt, &paths) == -1)
			return (0);
	}
	if (paths == NULL)
		return (directory_list(".", &opt));
	p_begin = paths;
	while (*paths != NULL)
	{
		directory_list(*paths, &opt);
		ft_printf("path: %s\n", *paths); // remove later.
		paths++;
	}
	free(p_begin);
	return (0);
}
