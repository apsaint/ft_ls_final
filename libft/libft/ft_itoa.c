/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:34:14 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/20 21:57:55 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static unsigned int	get_num_size_into_string(int n)
{
	unsigned int	size;

	size = n < 0 ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char				*ft_itoa(int n)
{
	long		nb;
	size_t		len;
	char		*strn;

	len = n == 0 ? 1 : get_num_size_into_string(n);
	if ((strn = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	strn[len--] = '\0';
	if (n == 0)
		*strn = '0';
	else if (n < 0)
		*strn = '-';
	nb = n < 0 ? (long)n * -1 : n;
	while (nb != 0)
	{
		strn[len--] = nb % 10 + 48;
		nb /= 10;
	}
	return (strn);
}
