/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 17:52:57 by bboutoil          #+#    #+#             */
/*   Updated: 2018/11/20 11:00:03 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	sign;

	nb = 0;
	while (*nptr && ft_isspace(*nptr))
		++nptr;
	sign = *nptr == '-' ? -1 : 1;
	if (*nptr == '-' || *nptr == '+')
		++nptr;
	while (*nptr && ft_isdigit(*nptr))
	{
		nb = nb * 10 + *nptr - '0';
		++nptr;
	}
	return (nb * sign);
}
