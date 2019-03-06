/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:46:17 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/22 15:37:13 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*begin = str;

	while (*str)
		str++;
	while (str >= begin)
	{
		if (*str == c)
			return ((char *)str);
		str--;
	}
	return (NULL);
}
