/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:06:18 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/22 15:49:11 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

/*
** APPEND_TO_LBUFFER
** desc: append data to buffer
** ret:  0 on success, GNL_ALLOC_ERROR on failure.
*/

static int	append_to_lbuffer(char **buffer, const char *str)
{
	char	*tmp;

	if (*buffer == NULL)
		*buffer = ft_strdup(str);
	else
	{
		tmp = *buffer;
		*buffer = ft_strjoin(*buffer, str);
		free(tmp);
	}
	if (*buffer == NULL)
		return (GNL_ALLOC_ERROR);
	return (0);
}

/*
** POP_FROM_BUFFER
** desc: pop from line buffer
** ret:  1 on success, 0 if buffer is empty, GNL_ALLOC_ERROR
** on mmemory alloc failure
*/

static int	pop_from_lbuffer(char **lbuff, char **output, size_t n)
{
	char	*tmp;

	if (n == 0)
	{
		if (*lbuff == NULL || **lbuff == '\0')
		{
			if (*lbuff != NULL)
				free(*lbuff);
			*output = NULL;
		}
		else
			*output = *lbuff;
		*lbuff = NULL;
		return (*output != NULL);
	}
	(*lbuff)[n - 1] = '\0';
	if ((*output = ft_strdup(*lbuff)) == NULL)
		return (GNL_ALLOC_ERROR);
	if ((tmp = ft_strdup(*lbuff + n)) == NULL)
		return (GNL_ALLOC_ERROR);
	ft_strdel(lbuff);
	*lbuff = tmp;
	return (1);
}

/*
** READ_LINE
** desc: internal function, read a line from a custom
** file descriptor buffer.
** ret:  1 on success, 0 if no line found, -1 on failure.
*/

int			ft_gnl(const int fd, char **line)
{
	static char	*buffer = NULL;
	char		buff[BUFF_SIZE + 1];
	int			bytes_read;
	char		*found;

	if (buffer != NULL && (found = ft_strchr(buffer, '\n')) != NULL)
	{
		if (pop_from_lbuffer(&buffer, line,
			(size_t)(found + 1 - buffer)) == -1)
			return (GNL_ERROR);
		return (GNL_SUCCESS);
	}
	if ((bytes_read = read(fd, buff, BUFF_SIZE)) == -1)
		return (GNL_ERROR);
	if (bytes_read == 0)
	{
		if (pop_from_lbuffer(&buffer, line, 0) == LINE_BUFFER_EMPTY)
			return (GNL_EOF);
		return (GNL_SUCCESS);
	}
	buff[bytes_read] = '\0';
	if (append_to_lbuffer(&buffer, buff) == GNL_ALLOC_ERROR)
		return (GNL_ERROR);
	return (ft_gnl(fd, line));
}
