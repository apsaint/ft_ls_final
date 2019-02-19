/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:55:04 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/19 17:35:44 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_ls.h"

int main(int ac, char const *av[])
{
	t_options	opt;
	char		**paths;

	paths = NULL;
	if (ac > 1)
		param_eval_all(av+1, ac-1, &opt, paths);
	if (*paths == NULL)
		directory_list(".", &opt);
	while (paths != NULL)
	{
		directory_list(*paths, &opt);
		paths++;
	}
	free(paths);
	return 0;
}
