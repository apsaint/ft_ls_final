/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:51:34 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/19 22:51:26 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*b1 = (const unsigned char	*)s1;
	const unsigned char	*b2 = (const unsigned char	*)s2;

	if (n == 0)
		return (0);
	while (n-- > 0)
		if (*b1++ != *b2++)
			return (*(b1 - 1) - *(b2 - 1));
	return (0);
}
