/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:45:32 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/06 08:40:57 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		flag_eval_others(const char *input, t_options *opt)
{
	if (*input == SPEC_LONG_G)
	{
		opt->display_func = &display_long_format;
		opt->flags |= FLAG_LONG_G;
	}
	else if (*input == SPEC_ONE_FILE_PER_LINE)
		opt->flags |= FLAG_FORCE_DISPLAY_ONE_BY_LINE;
	else if (*input == SPEC_OUTPUT_NOT_SORTED)
		opt->flags |= FLAG_NO_SORT;
	else if (*input == FLAG_SORT_BY_SIZE)
	{
		opt->flags |= FLAG_SORT_SIZE;
		opt->sort_func = &compare_by_size;
	}
	else
	{
		print_option_error(input);
		return (PARAM_ERROR);
	}
	return (0);
}

int				flag_eval(const char *input, t_options *opt)
{
	if (*input == SPEC_ALL)
		opt->flags |= (FLAG_SHOW_HIDDEN_FILE | FLAG_SHOW_MAP_DIR);
	else if (*input == SPEC_ALMOST_ALL)
		opt->flags |= (FLAG_SHOW_HIDDEN_FILE);
	else if (*input == SPEC_RECURSIVELY)
		opt->flags |= FLAG_LIST_SUBDIRS;
	else if (*input == SPEC_F)
		opt->flags |= FLAG_F;
	else if (*input == SPEC_DIR_AS_FILE)
		opt->flags |= FLAG_TREAT_AS_FILE;
	else if (*input == SPEC_LONG_FORMAT)
		opt->display_func = &display_long_format;
	else if (*input == SPEC_REVERSE)
		opt->flags |= FLAG_DISPLAY_REVERSE;
	else if (*input == SPEC_COLORIZE)
		opt->flags |= FLAG_COLORIZE;
	else if (*input == SPEC_INODE)
		opt->flags |= FLAG_DISPLAY_INODE;
	else if (*input == FLAG_SORT_BY_TIME)
		opt->sort_func = &compare_by_date;
	else
		return (flag_eval_others(input, opt));
	return (0);
}

void			resolve_flag_conflicts(t_options *opt)
{
	if (opt->flags & FLAG_TREAT_AS_FILE)
		opt->flags &= ~(FLAG_LIST_SUBDIRS);
	else if (opt->flags & FLAG_SORT_SIZE)
		opt->sort_func = &compare_by_size;
	if (opt->flags & FLAG_NO_SORT)
	{
		opt->flags |= (FLAG_SHOW_HIDDEN_FILE | FLAG_SHOW_MAP_DIR);
		opt->sort_func = NULL;
		opt->flags &= ~(FLAG_DISPLAY_REVERSE);
	}
	if (opt->flags & FLAG_FORCE_DISPLAY_ONE_BY_LINE)
		opt->display_func = &display_one_by_line;
}
