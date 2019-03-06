/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 22:42:56 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/23 10:36:13 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*cpy;
	size_t	len;

	if (n == 0)
		return (ft_strdup(""));
	len = ft_strnlen(s, n);
	if ((cpy = malloc(sizeof(char) * (len + 1))) != NULL)
	{
		cpy[len] = '\0';
		return (ft_memcpy(cpy, s, n));
	}
	return (NULL);
}
