/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:17:14 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/22 18:13:15 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_strarr_del(char ***arr)
{
	char	**tmp;

	tmp = *arr;
	while (*tmp != NULL)
		free(*tmp++);
	free(*arr);
}
