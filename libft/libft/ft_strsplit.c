/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:46:50 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/22 15:26:03 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_strtok(char const *s, const char delim, size_t *len)
{
	char	*begin;

	while (*s && *s == delim)
		s++;
	if (*s == '\0')
		return (NULL);
	begin = (char *)s;
	*len = 1;
	while (*(s + 1) && *(s + 1) != delim)
	{
		s++;
		*len = *len + 1;
	}
	return (begin);
}

static size_t	get_split_size(char const *s, const char delim)
{
	size_t	size;
	size_t	n;
	char	*p;

	n = 0;
	size = 0;
	p = (char *)s;
	while (1)
	{
		p = ft_strtok(p, delim, &n);
		if (p == NULL)
			break ;
		p = &p[n];
		size++;
	}
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**res;
	char			**begin;
	char			*new_line;
	size_t			l;

	if (s == NULL)
		return (NULL);
	l = get_split_size(s, c);
	if ((res = (char **)malloc(sizeof(char *) * l + 1)) == NULL)
		return (NULL);
	begin = res;
	res[l] = 0;
	while (1)
	{
		if ((s = ft_strtok(s, c, &l)) == NULL)
			break ;
		if ((new_line = (char *)malloc(sizeof(char) * l + 1)) == NULL)
			return (NULL);
		*res++ = new_line;
		ft_memcpy(new_line, s, l);
		new_line[l] = '\0';
		s = &s[l];
	}
	return (begin);
}
