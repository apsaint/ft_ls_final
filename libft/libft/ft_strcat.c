/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 00:01:56 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/20 11:28:46 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	const char	*begin = dest;

	while (*dest)
		++dest;
	ft_strcpy(dest, src);
	return ((char *)begin);
}
