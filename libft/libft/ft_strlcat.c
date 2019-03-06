/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:42:37 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/22 10:37:16 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tmp;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < n)
		i = i + 1;
	tmp = i;
	if (i < n)
	{
		while (src[j] != '\0' && j < n && i <= n - 2)
		{
			dest[i] = src[j];
			j = j + 1;
			i = i + 1;
		}
		dest[i] = '\0';
	}
	while (*src != '\0')
	{
		src = src + 1;
		tmp = tmp + 1;
	}
	return (tmp);
}
