/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:52:44 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/17 23:43:03 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;

	if ((tmp = (char *)malloc(n)) == NULL)
		return (dest);
	tmp = ft_memcpy(tmp, src, n);
	ft_memcpy(dest, tmp, n);
	free(tmp);
	return (dest);
}
