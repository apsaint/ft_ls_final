/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 12:16:33 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/02 12:17:53 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_TYPES_H
# define LS_TYPES_H

# include <sys/stat.h>
# include <string.h>
# include "ls_constants.h"

typedef struct		s_fstat
{
	struct stat		fstat;
	char			name[255 + (2 * COL_SIZE) + 1];
	int				type;
	char			*path;
	char			modes[11];
	char			owner[32];
	char			group[32];
	int				error;
	char			format_date[DATE_FORMAT_MAX_LEN];
}					t_fstat;

typedef struct		s_flist
{
	t_fstat			*data;
	size_t			size;
	size_t			count;
}					t_flist;

typedef struct		s_path
{
	char			*path_name;
	int				err;
	t_fstat			file_stat;
}					t_path;

typedef int	(*t_comp_func)(t_fstat *, t_fstat *);

typedef struct		s_options
{
	unsigned int	flags;
	int				(*display_func)(t_flist *, struct s_options *);
	t_comp_func		sort_func;
}					t_options;

typedef int	(*t_display_func)(t_flist *, t_options *);

#endif
