/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:45:37 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/17 23:47:04 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char		*begin = big;
	const char		*str;
	const char		*patt;

	while (*big && big < (begin + len))
	{
		str = big;
		patt = little;
		while (*str && *patt && *str == *patt && str <= (begin + len))
		{
			patt++;
			str++;
		}
		if (*patt == '\0')
			return ((char *)big);
		big++;
	}
	return (NULL);
}
