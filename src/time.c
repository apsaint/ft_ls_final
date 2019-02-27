/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:07:05 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/27 09:26:06 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>

int		get_time_format_style(time_t mod_time)
{
	const time_t	cur_time = time(NULL);

	if (cur_time - mod_time > UNIX_TIME_SIX_MONTH
	|| mod_time > cur_time + UNIX_TIME_SIX_MONTH)
		return (TIME_ALT_FORMAT);
	return (TIME_DEFAULT_FORMAT);
}

void	format_date(char *dst, char *date, time_t timestamp)
{
	ft_memcpy(dst, date + FTIME_DAY_MONTH_START_IDX, FTIME_DAY_MONTH_LEN);
	if (get_time_format_style(timestamp) == TIME_DEFAULT_FORMAT)
	{
		ft_memcpy(dst + FTIME_DAY_MONTH_LEN, date + FTIME_HOUR_START_IDX
				, FTIME_HOUR_LEN);
		*(dst + FTIME_DAY_MONTH_LEN + FTIME_HOUR_LEN) = '\0';
	}
	else
	{
		*(dst + FTIME_DAY_MONTH_LEN) = ' ';
		ft_memcpy((dst + FTIME_DAY_MONTH_LEN + 1),
			date + FTIME_YEAR_START_IDX, FTIME_YEAR_LEN);
		*(dst + FTIME_DAY_MONTH_LEN + FTIME_YEAR_LEN + 1) = '\0';
	}
}
