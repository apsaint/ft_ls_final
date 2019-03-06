/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sglist_get_node_at.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 23:56:30 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/17 23:44:28 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sgl_node	*ft_sglist_get_node_at(t_sglist *lst, unsigned int pos)
{
	t_sgl_node	*cur;

	if (pos >= lst->size)
		return (NULL);
	cur = lst->head;
	while (cur != NULL && pos != 0)
	{
		cur = cur->next;
		pos -= 1;
	}
	if (cur == NULL)
		return (NULL);
	return (cur);
}
