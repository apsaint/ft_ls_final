/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 22:38:08 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/17 23:40:28 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

t_list	*ft_lst_last(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
