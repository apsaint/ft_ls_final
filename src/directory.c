/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 21:06:24 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/21 11:17:54 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	directory_list(char *path, t_options *opt)
{
	t_elem elem;

	//init_t_elem(elem);
	printf("%s\n", path);
	fill_t_elem(path, &elem);
	printf("name: %s\n", elem.name);
	printf("type: %d\n", elem.type);
	printf("nb link: %d\n", elem.n_link);
	printf("Owner: %s\n", elem.owner);
	printf("Group: %s\n", elem.group);
	printf("date_modif: %d %s %d %d %d %d\n", (elem.date_modif).day, 
			(elem.date_modif).month, (elem.date_modif).year,
		(elem.date_modif).hour, (elem.date_modif).min,
		(elem.date_modif).sec);
	return (0);
	//return (NOT_IMPLEMENTED_FEATURE);
}
