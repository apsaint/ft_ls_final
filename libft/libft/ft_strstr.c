/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 12:46:07 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/22 10:38:25 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*str = haystack;
	const char	*patt = needle;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		while (*str && *patt && *str == *patt)
		{
			++str;
			++patt;
		}
		if (*patt == '\0')
			return ((char *)haystack);
		str = ++haystack;
		patt = needle;
	}
	return (NULL);
}
