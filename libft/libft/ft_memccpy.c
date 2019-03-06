/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:49:59 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/22 13:53:48 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dst_c;
	const unsigned char	*src_c = src;

	dst_c = dest;
	while (n-- > 0)
	{
		if ((unsigned char)(*dst_c++ = *src_c++) == (unsigned char)c)
			return (dst_c);
	}
	return (NULL);
}
