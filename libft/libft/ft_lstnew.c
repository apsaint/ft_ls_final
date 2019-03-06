/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:20:19 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/21 13:25:54 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;
	void	*contcpy;

	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		if ((contcpy = malloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(contcpy, content, content_size);
		lst->content = contcpy;
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}
