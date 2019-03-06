/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 23:18:20 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/22 09:58:17 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lcpy;
	t_list	*cur;

	if (lst == NULL)
		return (NULL);
	lcpy = f(lst);
	cur = lcpy;
	lst = lst->next;
	while (lst != NULL)
	{
		cur->next = f(lst);
		lst = lst->next;
		cur = cur->next;
	}
	return (lcpy);
}
