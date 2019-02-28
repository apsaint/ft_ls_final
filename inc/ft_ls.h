/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:19:27 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/28 11:09:08 by apsaint-         ###   ########.fr       */
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
# define SPEC_F					'F'
# define SPEC_REVERSE			'r'
# define SPEC_INODE				'i'
# define FLAG_SORT_BY_TIME		't'
# define FLAG_SORT_BY_SIZE		'S'
# define SPEC_ONE_FILE_PER_LINE	'1'
# define SPEC_OUTPUT_NOT_SORTED 'f'
# define DATE_FORMAT_MAX_LEN (32)

# define UNIX_TIME_SIX_MONTH (3600 * 24 * 30 * 6)
# define FTIME_DAY_MONTH_START_IDX (4)
# define FTIME_DAY_MONTH_LEN (7)
# define FTIME_HOUR_START_IDX (11)
# define FTIME_HOUR_LEN (5)
# define FTIME_YEAR_START_IDX (20)
# define FTIME_YEAR_LEN (4)

# define F_LIST_DEFAULT_SIZE (16)

# define LONG_FORMAT_MAX_ITEMS (8)

enum	e_format_style
{
	TIME_DEFAULT_FORMAT,
	TIME_ALT_FORMAT
};

enum	e_item_index
{
	ITEM_IDX_NLINKS,
	ITEM_IDX_OWNER,
	ITEM_IDX_GROUP,
	ITEM_IDX_SIZE,
	ITEM_IDX_MAJOR,
	ITEM_IDX_INO,
	ITEM_IDX_MINOR,
	ITEM_IDX_LAST_MOD,
	ITEM_IDX_PATH_NAME
};

typedef struct	s_fstat
{
	struct	stat	fstat;
	char			name[255];
	int				type;
	char			*path;
	char			modes[11];
	char			owner[32];
	char			group[32];
	int				error;
	char			format_date[DATE_FORMAT_MAX_LEN];
}				t_fstat;

typedef struct	s_flist
{
	t_fstat		*data;
	size_t		size;
	size_t		count;
}				t_flist;

enum	e_param_type
{
	PARAM_ERROR = -1,
	PARAM_PATH,
	PARAM_OPTION_SHORT,
	PARAM_OPTION_LONG,
	PARAM_OPTION_END
};

enum	e_option_flags
{
	FLAG_SHOW_HIDDEN_FILE = (1U << 0U),
	FLAG_SHOW_MAP_DIR = (1U << 1U),
	FLAG_LIST_SUBDIRS = (1U << 2U),
	FLAG_LONG_FORMAT = (1U << 3U),
	FLAG_DISPLAY_REVERSE = (1U << 4U),
	FLAG_DISPLAY_INODE = (1U << 5U),
	FLAG_F = (1U << 6U)
};

typedef int	(*t_comp_func)(t_fstat *, t_fstat *);

typedef struct		s_options
{
	unsigned int	flags;
	int				(*display_func)(t_flist *, struct s_options *, char *);
	t_comp_func		sort_func;
}					t_options;

typedef int(*t_display_func)(t_flist *, t_options *, char *);

int		param_eval_all(const char *params[], int count, t_options *opt,
		char ***paths);

int		directory_list(char *path, t_options *opt);

int		print_option_error(const char *option, int opt_type);
int		print_path_error(const char *path, int err_num);

int		f_list_init(t_flist *f_list);
int		f_list_add(t_flist *f_list, t_fstat *file);
int		f_list_destroy_storage(t_flist *f_list);

void	get_file_stat(t_fstat *fs, struct dirent *dp, char *path,
		t_options *opt);

int		display_one_by_line(t_flist *f_list, t_options *opt, char *path);
int		display_long_format(t_flist *f_list, t_options *opt, char *path);

int		combine_paths(char *path1, char *path2, char *output);
size_t	ls_itoa_min(unsigned long long nb, char *output);
void	format_date(char *dst, char *date, time_t timestamp);
int		param_display_order(t_flist *f_list, t_options *opt, int *start,
		int *end);
void	f_list_qsort(t_flist *f_list, t_options *opt, int max, int min);
void	swap(t_fstat *f1, t_fstat *f2);
int		compare_by_ascii(t_fstat *f1, t_fstat *f2);
int		compare_by_date(t_fstat *f1, t_fstat *f2);
int		compare_by_size(t_fstat *f1, t_fstat *f2);
int		compare_false(t_fstat *f1, t_fstat *f2);
int		total_block(t_flist *f_list);
int		get_width_by_int_item(int item);
int		display_long_bc(t_flist *f_list, int start, int *items_w);
int		display_long_l(t_flist *f_list, int start, int *items_w);
int		display_long_fd(t_flist *f_list, int start, int *items_w);
long	get_max_inode(t_flist *f_list);
void	add_type_file(t_fstat *fs, struct dirent *dp);
#endif
