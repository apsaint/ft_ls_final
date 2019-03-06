/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 22:31:57 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/18 19:44:37 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

size_t	ft_lstcount(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst != NULL)
	{
		++len;
		lst = lst->next;
	}
	return (len);
}
