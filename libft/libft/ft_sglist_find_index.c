/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sglist_find_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 21:20:51 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/19 10:25:24 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sglist_find_index(t_sglist *lst, int (*cmp)(), void *expected)
{
	int			pos;
	t_sgl_node	*cur;

	pos = 0;
	cur = lst->head;
	while (cur != NULL)
	{
		if (cmp(cur->content, expected) == 1)
			return (pos);
		cur = cur->next;
		++pos;
	}
	return (-1);
}
