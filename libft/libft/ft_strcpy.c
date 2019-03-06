/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 22:12:35 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/22 13:44:29 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	const char	*begin = dest;

	while (*src++)
		*dest++ = *(src - 1);
	*dest = '\0';
	return ((char *)begin);
}
