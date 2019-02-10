/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:55:04 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/10 21:31:38 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_ls.h"

int main(int ac, char const *av[])
{
	t_options	opt;
	char		**paths;

	paths = NULL;
	param_eval_all(av, ac, &opt, paths);

	while (paths != NULL)
	{
		directory_list((*paths)++, &opt);
	}
	return 0;
}
