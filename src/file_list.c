/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:09:48 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/20 22:22:04 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_ls.h"

int			f_list_init(t_flist *f_list)
{
	if ((f_list->data = (t_elem *)malloc(sizeof(t_elem) * F_LIST_DEFAULT_SIZE))
	== NULL)
		return (ALLOC_ERROR);
	ft_memset(f_list->data, 0, sizeof(t_elem) * F_LIST_DEFAULT_SIZE);
	f_list->count = 0;
	f_list->size = F_LIST_DEFAULT_SIZE;
	return (0);
}

int			f_list_destroy_storage(t_flist *f_list)
{
	free(f_list->data);
	ft_memset(f_list, 0, sizeof(t_flist));
	return (0);
}

static int	ensure_array_capacity(t_flist *f_list)
{
	const int	new_size_in_bytes = sizeof(t_elem) * (f_list->size *= 2);
	const int	bytes_to_copy = sizeof(t_elem) * f_list->count;
	t_elem	*tmp_array;

	if ((tmp_array = (t_elem *)malloc(new_size_in_bytes)) == NULL)
		return (ALLOC_ERROR);
	ft_memcpy(tmp_array, f_list->data, bytes_to_copy);
	free(f_list->data);
	f_list->data = tmp_array;
	return (0);
}

int			f_list_add(t_flist *f_list, t_elem *el)
{
	if (f_list->count == f_list->size)
	{
		if (ensure_array_capacity(f_list) == ALLOC_ERROR)
			return (ALLOC_ERROR);
	}
	ft_memcpy(&f_list->data[f_list->count++], el, sizeof(t_elem));
	return (0);
}