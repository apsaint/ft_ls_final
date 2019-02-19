/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:42:52 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/19 17:35:20 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_ls.h"

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
		opt->flags |= (FLAG_SHOW_HIDDEN_FILE | FLAG_SHOW_MAP_DIRECTORY);
	else if (*input == SPEC_ALMOST_ALL)
		opt->flags |= FLAG_SHOW_HIDDEN_FILE;
	else if (SPEC_RECURSIVELY)
		opt->flags |= FLAG_LIST_SUBDIRS;
	else
	{
		// TODO: print l erreur. "invalid flag x blabla"
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
*/
int	param_eval_all(const char *params[], int count, t_options *opt, char **paths)
{
	char	**path_begin;
	int		treat_as_path;
	int		par_type;

	path_begin = paths;
	treat_as_path = 0;
	if ((paths = (char **)malloc(sizeof(char *) * (count + 1))) == NULL)
		return (-1);
	while (count--)
	{
		if (treat_as_path == 1)
			*paths++ = (char *)*params;
		else if ((par_type = get_param_type(*params)) == PARAM_PATH)
			*paths++ = (char *)*params;
		else if (par_type == PARAM_OPTION_END)
			treat_as_path = 1;
		else
		{
			if(param_eval_flags(*params, opt, par_type) == PARAM_ERROR)
			{
				free(path_begin);
				return (-1);
			}
		}
		params++;
	}
	*(paths + 1) = NULL;
	paths = path_begin;
	return (0);
}
