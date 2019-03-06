/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:01:31 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/22 14:40:43 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cp;

	if (s == NULL || (cp = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	*(cp + len) = '\0';
	return (ft_memcpy(cp, (s + start), len));
}
