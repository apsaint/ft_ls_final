/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:22:53 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/22 14:51:44 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	dlen;
	char	*cp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dlen = ft_strlen(s1) + ft_strlen(s2);
	if ((cp = (char *)ft_strnew(sizeof(char) * (dlen + 1))) == NULL)
		return (NULL);
	while (*s1 != '\0')
		*cp++ = *s1++;
	while (*s2 != '\0')
		*cp++ = *s2++;
	*cp = '\0';
	return (cp - dlen);
}
