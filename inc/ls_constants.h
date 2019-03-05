/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_constants.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 12:13:57 by bboutoil          #+#    #+#             */
/*   Updated: 2019/03/05 14:38:40 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_CONSTANTS_H
# define LS_CONSTANTS_H

# define ALLOC_ERROR (-1)
# define NOT_IMPLEMENTED_FEATURE (-1)
# define DATE_FORMAT_MAX_LEN (32)
# define UNIX_TIME_SIX_MONTH (3600 * 24 * 30 * 6)
# define FTIME_DAY_MONTH_START_IDX (4)
# define FTIME_DAY_MONTH_LEN (7)
# define FTIME_HOUR_START_IDX (11)
# define FTIME_HOUR_LEN (5)
# define FTIME_YEAR_START_IDX (20)
# define FTIME_YEAR_LEN (4)
# define LONG_FORMAT_MAX_ITEMS (8)
# define F_LIST_DEFAULT_SIZE (16)

# define CNRM  "\x1B[0m"
# define CRED  "\x1B[31m"
# define CGRN  "\x1B[32m"
# define CYEL  "\x1B[33m"
# define CBLU  "\x1B[34m"
# define CMAG  "\x1B[35m"
# define CCYN  "\x1B[36m"
# define CWHT  "\x1B[37m"
# define COL_SIZE (16)

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
	FLAG_F = (1U << 6U),
	FLAG_LONG_G = (1U << 7U),
	FLAG_HIDE_TOTAL = (1U << 8U),
	FLAG_COLORIZE = (1U << 9U),
	FLAG_TREAT_AS_FILE = (1U << 10U),
	FLAG_NO_READ = (1U << 11U)
};

#endif
