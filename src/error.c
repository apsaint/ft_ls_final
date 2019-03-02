/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:07:57 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/02 12:22:43 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ls.h"
#include "libft.h"

int	print_option_error(const char *option, int opt_type)
{
	char	str[256];

	ft_memset(str, 0, sizeof(str));
	ft_strlcat(str, ""PROGRAM_NAME": ", sizeof(str));
	ft_strlcat(str, "invalid option -- ", sizeof(str));
	ft_strlcat(str, option, sizeof(str));
	ft_putendl_fd(str, STDERR_FILENO);
	return (0);
}

int	print_path_error(const char *path, int err_num)
{
	char	str[256];
	char	*ptr;

	ptr = ft_strrchr(path, '/');
	ft_memset(str, 0, sizeof(str));
	ft_strlcat(str, ""PROGRAM_NAME": ", sizeof(str));
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("", STDERR_FILENO);
	if (ptr == NULL)
		ft_putstr_fd(path, STDERR_FILENO);
	else
		ft_putstr_fd(++ptr, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(err_num), STDERR_FILENO);
	return (0);
}
