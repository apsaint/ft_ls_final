/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:03:21 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/23 10:10:13 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lst_find(t_list *lst, void *data_ref, int (*cmp)())
{
	while (lst != NULL)
	{
		if (cmp(lst->content, data_ref) == 1)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
