/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sglist_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:45:07 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/19 09:59:43 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sglist	*ft_sglist_new(void *content)
{
	t_sglist	*lst;

	lst = ft_sglist_new_empty();
	if (lst == NULL)
		return (NULL);
	if (ft_sglist_append(lst, content) == SGL_ALLOC_FAILURE)
		return (NULL);
	return (lst);
}
