/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:42:52 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/05 22:20:56 by bboutoil         ###   ########.fr       */
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
			return (PARAM_OPTION_SHORT);
		}
		if (*(param + 1) != '\0')
			return (PARAM_OPTION_SHORT);
	}
	return (PARAM_PATH);
}

static int	param_eval_flags(const char *input, t_options *data)
{
	while (*input)
	{
		if (flag_eval(input, data) == PARAM_ERROR)
			return (PARAM_ERROR);
		input++;
	}
	return (0);
}

static int	param_eval_all_internal(const char *params[], int count,
t_options *opt, t_path **paths)
{
	const t_path	*begin = *paths;
	static int	treat_as_path = 0;
	int			par_type;

	while (count--)
	{
		if (treat_as_path == 1)
			((*paths)++)->path_name = (char *)*params;
		else if ((par_type = get_param_type(*params)) == PARAM_PATH)
		{
			treat_as_path = 1;
			((*paths)++)->path_name = (char *)*params;
		}
		else if (par_type == PARAM_OPTION_END && *(*params + 2) == '\0')
			treat_as_path = 1;
		else
		{
			if (param_eval_flags(++*params, opt) == PARAM_ERROR)
				return (-1);
		}
		params++;
	}
	(*paths)->path_name = NULL;
	*paths = (t_path *)begin;
	return (0);
}

int			param_eval_all(const char *params[], int count,
t_options *opt, t_path **paths)
{
	if ((*paths = (t_path *)malloc(sizeof(t_path) * (count + 1))) == NULL)
		return (-1);
	if (param_eval_all_internal(params, count, opt, paths) == -1)
	{
		free(paths);
		return (-1);
	}
	resolve_flag_conflicts(opt);
	return (0);
}
