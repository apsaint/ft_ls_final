/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:15:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/02/22 15:39:51 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Add s2 to s1, returns pointer of fresh s1 while freeing old one
** If s1	NULL return dup of s2
** If s2 	NULL return s1
** If s1&s2	NULL return NULL
*/

#include "libft.h"

char	*ft_stradd(char *s1, char *s2)
{
	char	*p;

	p = ft_strjoin(s1, s2);
	ft_memdel((void **)&s1);
	return (p);
}