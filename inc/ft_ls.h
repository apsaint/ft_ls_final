/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:19:27 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/05 21:49:21 by bboutoil         ###   ########.fr       */
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
# include "ft_printf.h"
# include "ls_types.h"
# include "ls_constants.h"

/*
** *****************************************************************************
** GLOBAL CONFIG ***************************************************************
*/

# define PROGRAM_NAME				"ft_ls"
# define OPTION_SPECIFIER			'-'
# define DEFAULT_PATH				"."
# define SPEC_LONG_FORMAT			'l'
# define SPEC_LONG_G				'g'
# define SPEC_ALL					'a'
# define SPEC_ALMOST_ALL			'A'
# define SPEC_RECURSIVELY			'R'
# define SPEC_F						'F'
# define SPEC_REVERSE				'r'
# define SPEC_INODE					'i'
# define SPEC_ONE_FILE_PER_LINE		'1'
# define SPEC_OUTPUT_NOT_SORTED 	'f'
# define FLAG_SORT_BY_TIME			't'
# define FLAG_SORT_BY_SIZE			'S'
# define SPEC_COLORIZE				'G'
# define SPEC_DIR_AS_FILE			'd'

/*
** *****************************************************************************
** PUBLIC FUNCTIONS ************************************************************
*/

/*
** PARAM MOD **
** --------- **
*/

int		param_eval_all(const char *params[], int count, t_options *opt,
		t_path **paths);
int		flag_eval(const char *input, t_options *opt);
void	resolve_flag_conflicts(t_options *opt);



/*
** DIRECTORY MOD **
** ------------- **
*/

int		directory_list(char *path, t_options *opt, int show_dir);

/*
** ERROR MOD **
** --------- **
*/

void	error_qsort(t_path *error, int min, int max);
void	swap_str(t_path *s1, t_path *s2);
int		print_option_error(const char *option, int opt_type);
int		print_path_error(const char *path, int err_num, t_options *opt);

/*
** FILE MOD **
** -------- **
*/

int		f_list_init(t_flist *f_list);
int		f_list_add(t_flist *f_list, t_fstat *file);
int		f_list_destroy_storage(t_flist *f_list);
void		f_list_reverse(t_flist *f_list);
void	get_file_stat(t_fstat *fs, struct dirent *dp, char *path,
		t_options *opt);
void	f_list_qsort(t_flist *f_list, t_options *opt, int max, int min);
void	swap(t_fstat *f1, t_fstat *f2);
int		compare_by_ascii(t_fstat *f1, t_fstat *f2);
int		compare_by_date(t_fstat *f1, t_fstat *f2);
int		compare_by_size(t_fstat *f1, t_fstat *f2);
void	set_file_name(t_fstat *file, char *path, t_options *opt);

/*
** DISPLAY MOD **
** ----------- **
*/

int		display_one_by_line(t_flist *f_list, t_options *opt);
int		display_long_format(t_flist *f_list, t_options *opt);
int		total_block(t_flist *f_list);
int		get_width_by_int_item(int item);
int		display_long_bc(t_flist *f_list, int start, int *items_w,
		t_options *opt);
int		display_long_l(t_flist *f_list, int start, int *items_w,
		t_options *opt);
int		display_long_fd(t_flist *f_list, int start, int *items_w,
		t_options *opt);
long	get_max_inode(t_flist *f_list);
int		param_display_order(t_flist *f_list, t_options *opt, int *start,
		int *end);

/*
** PATH MODULE **
** ----------- **
*/

int		combine_paths(char *path1, char *path2, char *output);
int		get_path_count(t_path *paths);
int		get_stats_from_all_paths(t_path *paths, t_options *opt);
int		get_file_stat_by_path(t_fstat *file, char *path, t_options *opt);

/*
** UTILS MODULE **
** ------------ **
*/

size_t	ls_itoa_min(unsigned long long nb, char *output);
void	format_date(char *dst, char *date, time_t timestamp);
char	get_permission_sticky(mode_t m, char c);
char	get_permission_uid(mode_t m, char c);
char	get_permission_gid(mode_t m, char c);
#endif
