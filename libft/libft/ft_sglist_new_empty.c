/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sglist_new_empty.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:04:51 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/17 23:44:30 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_sglist	*ft_sglist_new_empty(void)
{
	t_sglist	*lst;

	lst = (t_sglist *)malloc(sizeof(t_sglist));
	if (lst == NULL)
		return (NULL);
	lst->head = NULL;
	lst->last = NULL;
	lst->size = 0;
	return (lst);
}
