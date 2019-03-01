/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:42:52 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/01 19:21:56 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_ls.h"
#include "libft.h"

static int	get_param_type(const char *param)
{
	if (*param == OPTION_SPECIFIER)
	{
		if (*(param + 1) == OPTION_SPECIFIER)
		{
			if (*(param + 2) == '\0')
				return (PARAM_OPTION_END);
			return (PARAM_PATH);
		}
		if (*(param + 1) != '\0')
			return (PARAM_OPTION_SHORT);
	}
	return (PARAM_PATH);
}

static int	eval_short_flag(const char *input, t_options *opt)
{
	if (*input == SPEC_ALL)
		opt->flags |= (FLAG_SHOW_HIDDEN_FILE | FLAG_SHOW_MAP_DIR);
	else if (*input == SPEC_ALMOST_ALL)
		opt->flags |= (FLAG_SHOW_HIDDEN_FILE);
	else if (*input == SPEC_RECURSIVELY)
		opt->flags |= FLAG_LIST_SUBDIRS;
	else if (*input == SPEC_F)
		opt->flags |= FLAG_F;
	else if (*input == SPEC_LONG_FORMAT)
		opt->display_func = &display_long_format;
	else if (*input == SPEC_LONG_G)
	{
		opt->display_func = &display_long_format;
		opt->flags |= FLAG_LONG_G;
	}
	else if (*input == SPEC_REVERSE)
		opt->flags |= FLAG_DISPLAY_REVERSE;
	else if (*input == SPEC_INODE)
		opt->flags |= FLAG_DISPLAY_INODE;
	else if (*input == FLAG_SORT_BY_TIME)
		opt->sort_func = &compare_by_date;
	else if (*input == FLAG_SORT_BY_SIZE)
		opt->sort_func = &compare_by_size;
	else if (*input == SPEC_ONE_FILE_PER_LINE)
		opt->display_func = &display_one_by_line;
	else if (*input == SPEC_OUTPUT_NOT_SORTED)
	{
		opt->flags |= (FLAG_SHOW_HIDDEN_FILE | FLAG_SHOW_MAP_DIR);
		opt->sort_func = NULL;
	}
	else
	{
		print_option_error(input, PARAM_OPTION_SHORT);
		return (PARAM_ERROR);
	}
	return (0);
}

static int	param_eval_flags(const char *input, t_options *data)
{
	while (*input)
	{
		if (eval_short_flag(input, data) == PARAM_ERROR)
			return (PARAM_ERROR);
		input++;
	}
	return (0);
}

int	param_eval_all(const char *params[], int count, t_options *opt, t_path **paths)
{
	t_path	*path_begin;
	int		treat_as_path;
	int		par_type;

	treat_as_path = 0;
	if ((*paths = (t_path *)malloc(sizeof(t_path) * (count + 1))) == NULL)
		return (-1);
	path_begin = *paths;
	while (count--)
	{
		if (treat_as_path == 1)
			((*paths)++)->path_name = (char *)*params;
		else if ((par_type = get_param_type(*params)) == PARAM_PATH)
		{
			treat_as_path = 1;
			((*paths)++)->path_name = (char *)*params;
		}
		else if (par_type == PARAM_OPTION_END)
			treat_as_path = 1;
		else
		{
			if(param_eval_flags(++*params, opt) == PARAM_ERROR)
			{
				free(path_begin);
				return (-1);
			}
		}
		params++;
	}
	(*paths)->path_name = NULL;
	*paths = path_begin;
	return (0);
}
