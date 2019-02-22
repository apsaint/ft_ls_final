/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:22:33 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/22 14:46:08 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	combine_paths(char *path1, char *path2, char *output)
{
	
	const	int s = ft_strlen(path1);
	ft_strlcat(output, path1, 4097);
	if (*(path1 + s - 1) == '/')
	{
		ft_strlcat(output, path2, 4097);
	}
	else
	{
		ft_strlcat(output, "/", 4097);
		ft_strlcat(output, path2, 4097);
	}
	return (0);
}