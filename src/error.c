/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:07:57 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/03 13:33:47 by apsaint-         ###   ########.fr       */
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
	ft_strlcat(str, "illegal option -- ", sizeof(str));
	ft_strlcat(str, option, sizeof(str));
	ft_strlcat(str, "\nusage: ./ft_ls [-AFGSadfgilrt1] [file ...]", sizeof(str));
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

int		compare_string(char *s1, char *s2)
{
	return ((ft_strcmp(s1, s2) > 0 ? 1 : -1));
}

int		partition_error(char **error, int min, int max)
{
	int		i;
	int		j;
	char	*pivot;

	i = min - 1;
	j = min;
	pivot = error[max];
	while (j <= (max - 1))
	{
		if (compare_string(error[j], pivot) == -1)
		{
			i++;
			swap(error[i], error[j]);
		}
		j++;
	}
	swap(error[i + 1], error[max]);
	return (i + 1);
}

void	error_qsort(char **error, int max, int min)
{
	int		part;

	if (min < max)
	{
		part = partition_error(error, min, max);
		error_qsort(error, part - 1, min);
		error_qsort(error, max, part + 1);
	}
}
