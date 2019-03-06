/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sglist_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 18:07:41 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/19 10:30:12 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_sglist_find(t_sglist *lst, int (*cmp)(), void *expected)
{
	t_sgl_node	*cur;

	cur = lst->head;
	while (cur != NULL)
	{
		if (cmp(cur->content, expected) == 1)
			return (cur->content);
		cur = cur->next;
	}
	return (NULL);
}
