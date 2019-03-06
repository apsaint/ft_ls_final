/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sglist_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 21:39:19 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/18 13:11:29 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_sglist_remove(t_sglist *lst, void *data)
{
	t_sgl_node	*cur;
	t_sgl_node	*prev;

	cur = lst->head;
	prev = NULL;
	while (cur != NULL)
	{
		if (cur->content == data)
			break ;
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)
		return (0);
	if (prev == NULL)
		lst->head = cur->next;
	else
		prev->next = cur->next;
	if (cur == lst->last)
		lst->last = NULL;
	lst->size -= 1;
	free(cur);
	return (1);
}
