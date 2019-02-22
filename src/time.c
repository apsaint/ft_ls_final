/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:07:05 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/22 09:19:23 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		convert_year(char **time)
{
	int		y;
	int		i;

	y = 0;
	i = 3;
	(*time)++;
	while (i > 0)
		y += (*((*time)++) - '0') * ft_pow(10, i--);
	y += *((*time)++) - '0';
	return (y);
}

int		convert_time(char **time)
{
	int		t;

	t = 0;
	(*time)++;
	if (**time != '0')
		t = (**time - '0') * 10;
	(*time)++;
	t += *((*time)++) - '0';
	return (t);
}
