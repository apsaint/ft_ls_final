/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:19:27 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/25 11:21:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
# include "libft.h"

# define ALLOC_ERROR (-1)
# define NOT_IMPLEMENTED_FEATURE (-1)
# define PROGRAM_NAME "ft_ls"

# define OPTION_SPECIFIER '-'
# define DEFAULT_PATH "."

# define SPEC_LONG_FORMAT		'l'
# define SPEC_ALL				'a'
# define SPEC_ALMOST_ALL		'A'
# define SPEC_RECURSIVELY		'R'
# define SPEC_REVERSE			'r'
# define FLAG_SORT_BY_TIME		't'
# define FLAG_SORT_BY_SIZE		'S'

# define DATE_FORMAT_MAX_LEN (32)

typedef struct s_fstat
{
	char		name[255];
	int			type;
	char		*path;
	char		modes[11];
	int			n_link;
	char		owner[32];
	char		group[32];
	int			size;
	int			n_block;
	int			error;
	time_t		mod_time;
	char	format_date[DATE_FORMAT_MAX_LEN];
}				t_fstat;

#define F_LIST_DEFAULT_SIZE (16)

typedef struct	s_flist
{
	t_fstat		*data;
	size_t		size;
	size_t		count;
}				t_flist;

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
	FLAG_SHOW_MAP_DIR = (1U << 1U),
	FLAG_LIST_SUBDIRS = (1U << 2U),
	FLAG_LONG_FORMAT = (1U << 3U),
	FLAG_DISPLAY_REVERSE = (1U << 4U),
};

typedef int (*t_comp_func)(t_fstat *, t_fstat *);

typedef struct		s_options
{
	unsigned int	flags;
	int				(*display_func)(t_flist *, struct s_options *, char *);
	t_comp_func		sort_func;
}					t_options;

typedef int(*t_display_func)(t_flist *, t_options *, char *);

int		param_eval_all(const char *params[], int count, t_options *opt, char ***paths);

int		directory_list(char *path, t_options *opt);

int		print_option_error(const char *option, int opt_type);
int 	print_path_error(const char *path, const char *content, int err_num);

int		f_list_init(t_flist *f_list);
int		f_list_add(t_flist *f_list, t_fstat *file);
int		f_list_destroy_storage(t_flist *f_list);

void	get_file_stat(t_fstat *fs, struct dirent *dp, char *path);

int		display_one_by_line(t_flist *f_list, t_options *opt, char *path);
int		display_long_format(t_flist *f_list, t_options *opt, char *path);

int		combine_paths(char *path1, char *path2, char *output);
size_t	ls_itoa_min(unsigned long long nb, char *output);
void	format_date(char *dst, char *date, time_t timestamp);
int		param_display_order(t_flist *f_list, t_options *opt, int *start, int *end);
void	f_list_qsort(t_flist *f_list, t_options *opt, int max, int min);
void	swap(t_fstat *f1, t_fstat *f2);
int		compare_by_ascii(t_fstat *f1, t_fstat *f2);
int		compare_by_date(t_fstat *f1, t_fstat *f2);
int		compare_by_size(t_fstat *f1, t_fstat *f2);

#endif
