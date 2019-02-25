/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:42:52 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/25 11:20:28 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_ls.h"
#include "libft.h"

int	show_errors_and_destroy_errlist(char **errors, char **begin)
{
	while(*errors != NULL)
	{
		print_path_error(*errors, "cannot open directory ", ENOENT);
		errors++;
	}
	free(begin);
	return (0);
}

int add_param_to_pathlist_or_errlist(char ***paths, char ***errors, 
const char *param)
{
	struct stat	s_stat;
	
	errno = 0;
	if ((stat(param, &s_stat) == -1) && (errno == ENOENT))
		*((*errors)++) = (char *)param;
	else
		*((*paths)++) = (char *)param;
	return (0);
}

int	get_param_type(const char *param)
{
	if (*param == OPTION_SPECIFIER)
	{
		if (*(param + 1) == OPTION_SPECIFIER)
		{
			if (*(param + 2) == '\0')
				return (PARAM_OPTION_END);
			return (PARAM_OPTION_LONG);
		}
		if (*(param + 1) != '\0')
			return (PARAM_OPTION_SHORT);
	}
	return (PARAM_PATH);
}

int	eval_short_flag(const char *input, t_options *opt)
{
	if (*input == SPEC_ALL)
		opt->flags |= (FLAG_SHOW_HIDDEN_FILE | FLAG_SHOW_MAP_DIR);
	else if (*input == SPEC_ALMOST_ALL)
		opt->flags |= (FLAG_SHOW_HIDDEN_FILE);
	else if (*input == SPEC_RECURSIVELY)
		opt->flags |= FLAG_LIST_SUBDIRS;
	else if (*input == SPEC_LONG_FORMAT)
		opt->display_func = &display_long_format;
	else if (*input == SPEC_REVERSE)
		opt->flags |= FLAG_DISPLAY_REVERSE;
	else if (*input == FLAG_SORT_BY_TIME)
		opt->sort_func = &compare_by_date;
	else if (*input == FLAG_SORT_BY_SIZE)
		opt->sort_func = &compare_by_size;
	else
	{
		print_option_error(input, PARAM_OPTION_SHORT);
		return (PARAM_ERROR);
	}
	return (0);
}

int param_eval_flags(const char *input, t_options *data, int flag_type)
{
	if (flag_type == PARAM_OPTION_SHORT)
	{
		input++;
		while (*input)
		{
			if (eval_short_flag(input, data) == PARAM_ERROR)
				return (PARAM_ERROR);
			input++;
		}
	}
	else if (flag_type == PARAM_OPTION_LONG)
	{
		// function pas encore implementee, peut etre
		// jamais, voir avec apoline si on le fait en bonus.
		return (NOT_IMPLEMENTED_FEATURE);
	}
	return (0);
}

/*
	note sur l implementation :
	la fonction malloc un tableau qui sert a regrouper les path. la fonction
	ne malloc pas les string contenant ces paths, c est inutile il suffit
	de reprendre les pointeurs existants (du argv du main, en l occurence params
	dans cette fonction).

	les flags sont stockees dans la structures t_options.
	un -- est considere comme la fin des args. Tout ce qui vient apres
	ca est traite comme un path par ls. voir notes.txt. la variable
	treat_as_path sert a ajuster ce comportement.

	Le char *** fait peur mais c est pas complique, c est juste pour avoir
	l adresse du tableau de strings. (si pas compris demander expli)
*/

int	param_init_arrays(char ***paths, char ***errors, int count)
{
	if ((*paths = (char **)malloc(sizeof(char *) * (count + 1))) == NULL)
		return (-1);
	if ((*errors = (char **)malloc(sizeof(char *) * (count + 1))) == NULL)
	{
		free(*paths);
		return (-1);
	}
	return (0);
}

int	param_eval_all(const char *params[], int count, t_options *opt, char ***paths)
{
	char	**path_begin;
	char	**error_begin;
	char	**errors;
	int		treat_as_path;
	int		par_type;

	treat_as_path = 0;
	if (param_init_arrays(paths, &errors, count) == -1)
		return (-1);
	path_begin = *paths;
	error_begin = errors;
	while (count--)
	{
		if (treat_as_path == 1)
			add_param_to_pathlist_or_errlist(paths, &errors, *params);
		else if ((par_type = get_param_type(*params)) == PARAM_PATH)
			add_param_to_pathlist_or_errlist(paths, &errors, *params);
		else if (par_type == PARAM_OPTION_END)
			treat_as_path = 1;
		else
		{
			if(param_eval_flags(*params, opt, par_type) == PARAM_ERROR)
			{
				free(path_begin);
				free(error_begin);
				return (-1);
			}
		}
		params++;
	}
	**paths = NULL;
	*errors = NULL;
	*paths = path_begin;
	errors = error_begin;
	show_errors_and_destroy_errlist(errors, error_begin);
	return (0);
}
