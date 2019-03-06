/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:39:25 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/17 23:45:08 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
			return ((char *)str);
		++str;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return (NULL);
}
