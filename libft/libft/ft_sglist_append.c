/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sglist_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:12:08 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/19 10:29:42 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_sglist_append(t_sglist *lst, void *data)
{
	t_sgl_node	*el;

	el = (t_sgl_node *)malloc(sizeof(t_sgl_node));
	if (el == NULL)
		return (SGL_ALLOC_FAILURE);
	el->content = data;
	el->next = NULL;
	if (lst->last == NULL)
	{
		lst->head = el;
		lst->last = el;
	}
	else
	{
		lst->last->next = el;
		lst->last = el;
	}
	lst->size += 1;
	return (0);
}
