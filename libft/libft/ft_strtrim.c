/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:47:39 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/22 15:02:59 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	istrim(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' ? 1 : 0);
}

char		*ft_strtrim(char const *s)
{
	size_t	n;
	char	*cpy;

	if (s == NULL)
		return (NULL);
	n = ft_strlen(s);
	cpy = (char *)s;
	while (&s[n - 1] >= cpy && istrim(s[n - 1]))
		n--;
	if (n == 0)
		return (ft_strnew(1));
	while (*s && istrim(*s))
	{
		s++;
		n--;
	}
	if ((cpy = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	cpy[n] = '\0';
	return (ft_memcpy(cpy, s, n));
}
