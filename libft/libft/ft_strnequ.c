/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:44:49 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/22 15:22:48 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);
	if (n == 0)
		return (1);
	while (n-- > 0)
	{
		if (*s1 != *s2++)
			return (0);
		if (*s1++ == '\0')
			return (1);
	}
	return (1);
}
