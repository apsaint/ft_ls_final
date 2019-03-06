/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:43:06 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/22 15:24:27 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*cp;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	if ((cp = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cp[i] = f((unsigned int)i, s[i]);
		++i;
	}
	cp[i] = '\0';
	return (cp);
}
