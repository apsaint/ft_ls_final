/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sglist_remove_at.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 23:28:08 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/17 23:44:41 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_sglist_remove_at(t_sglist *lst, unsigned int pos)
{
	t_sgl_node	*node;
	void		*data;

	node = ft_sglist_get_node_at(lst, pos);
	if (node == NULL)
		return (NULL);
	data = node->content;
	if (node->next == NULL)
		free(node);
	else
	{
		node->content = node->next->content;
		node->next = node->next->next;
		free(node->next);
	}
	return (data);
}
