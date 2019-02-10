/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:19:27 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/10 21:52:18 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define PROGRAM_NAME "ft_ls"
# define OPTION_SPECIFIER '-'
# define DEFAULT_PATH "."


typedef struct		s_options
{
	unsigned int	flags;
}					t_options;

int	param_eval_all(const char *params[], int count, t_options *opt, char **paths);
int	directory_list(char *path, t_options *opt);

#endif

/* enum e_file_flags
{
	FLAG_SHOW_HIDDEN_FILE = (1U << 0U),
	FLAG_SHOW_MAP_DIRECTORY = (1U << 1U),
};

enum e_display_options
{
	DISPLAY_ONE_LINE,
	DISPLAY_COLUMN
};

enum e_sorting_options
{
	SORT_ALPHABETICALY,
	SORT_BY_SIZE,
	SORT_BY_TIME_MODIFICATION,
}; */