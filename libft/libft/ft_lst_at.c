/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 23:04:17 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/17 23:40:22 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list	*ft_lst_at(t_list *lst, unsigned int nb)
{
	while (--nb != 0 && lst != NULL)
		lst = lst->next;
	if (nb != 0)
		return (NULL);
	return (lst);
}
