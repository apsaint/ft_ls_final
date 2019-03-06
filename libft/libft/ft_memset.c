/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 20:24:27 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/17 23:43:06 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (size-- > 0)
		*ptr++ = (unsigned char)c;
	return (s);
}
