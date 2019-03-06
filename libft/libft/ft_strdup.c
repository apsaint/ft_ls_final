/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:40:52 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/17 23:45:45 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	n;
	void	*cpy;

	n = ft_strlen(s) + 1;
	if (n > 0)
	{
		cpy = malloc(n * sizeof(char));
		if (cpy != NULL)
			return ((char *)ft_memcpy(cpy, s, n));
	}
	return (NULL);
}
