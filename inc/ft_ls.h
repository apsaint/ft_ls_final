/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:19:27 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/20 14:37:11 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>

# define NOT_IMPLEMENTED_FEATURE (-1)
# define PROGRAM_NAME "ft_ls"
# define OPTION_SPECIFIER '-'
# define DEFAULT_PATH "."

# define SPEC_LONG_FORMAT    'l'
# define SPEC_ALL            'a'
# define SPEC_ALMOST_ALL     'A'
# define SPEC_RECURSIVELY    'R'

typedef struct s_telem
{
	char	month[3];
	int		day;
	int		year;
	int		hour;
	int		min;
	int		sec;
}				t_telem;

typedef struct s_elem
{
	char		*name;
	char		type;
	char		*path;
	char		modes[10];
	int			n_link;
	char		*owner;
	char		*group;
	int			size;
	t_telem		*date_modif;
	t_telem		*date_crea;
}				t_elem;

enum e_param_type
{
	PARAM_ERROR = -1,
	PARAM_PATH,
	PARAM_OPTION_SHORT,
	PARAM_OPTION_LONG,
	PARAM_OPTION_END
};

enum e_option_flags
{
	FLAG_SHOW_HIDDEN_FILE = (1U << 0U),
	FLAG_SHOW_MAP_DIRECTORY = (1U << 1U),
	FLAG_LIST_SUBDIRS = (1U << 2U),
};

typedef struct		s_options
{
	unsigned int	flags;
}					t_options;

enum e_display_options
{
	DISPLAY_ONE_LINE,
	DISPLAY_COLUMN,
};

enum e_sorting_options
{
	SORT_ALPHABETICALY,
	SORT_BY_SIZE,
	SORT_BY_TIME_MODIFICATION,
};

int	param_eval_all(const char *params[], int count, t_options *opt, char ***paths);
int	directory_list(char *path, t_options *opt);
int	print_option_error(const char *option, int opt_type);
#endif
