/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:07:57 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/27 15:11:04 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ls.h"
#include "libft.h"

// TODO: Impl semble merdique, a test, et voir si y a pas plus
// simple a faire.
int	print_option_error(const char *option, int opt_type)
{
	char	str[256];

	ft_memset(str, 0, sizeof(str));

	if (opt_type == PARAM_OPTION_SHORT)
	{
		ft_strlcat(str, ""PROGRAM_NAME": ", sizeof(str));
		ft_strlcat(str, "invalid option -- '", sizeof(str));
		ft_strlcat(str, option, sizeof(str));
		ft_strlcat(str, "'", sizeof(str));
	}
	else
	{
		// si c est un long option, attention la longueur
		// etre potentiellement infinie il faudra gerer ca
	}
	ft_putendl_fd(str, STDERR_FILENO);
	return(0);
}

// impl tres merdique aussi, je verrais plus tard pour ajouter
// une fonction fstring a la libft histoire de remedier a ces enchainements
// de strlcat
int print_path_error(const char *path, const char *content, int err_num)
{
	char	str[256];

	ft_memset(str, 0, sizeof(str));
	ft_strlcat(str, ""PROGRAM_NAME": ", sizeof(str));
	ft_strlcat(str, content, sizeof(str));
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(err_num), STDERR_FILENO);
	return (0);
}
