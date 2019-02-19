/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:07:57 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/19 22:31:11 by bboutoil         ###   ########.fr       */
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