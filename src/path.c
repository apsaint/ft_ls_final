/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:21:56 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/27 22:09:01 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	show_errors_and_destroy_errlist(char **errors, char **begin)
{
	while (*errors != NULL)
	{
		if (**errors++ == '\0')
		{
			print_path_error("fts_open", ENOENT);
			free(begin);
			return (PARAM_ERROR);
		}
	}
	errors = begin;
	while(*errors != NULL)
	{
		print_path_error(*errors, ENOENT);
		errors++;
	}
	free(begin);
	return (0);
}