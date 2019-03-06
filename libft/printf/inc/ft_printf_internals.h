/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internals.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:23:36 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/23 09:50:19 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNALS_H
# define FT_PRINTF_INTERNALS_H

# include <stdarg.h>
# include <string.h>

/*
** ARG SYMBOLS
*/

# define SYM_SPECIFIER	'%'
# define SYM_PRECISION	'.'
# define SYM_WILDCHAR	'*'
# define ATTR_ZERO		'0'
# define ATTR_PLUS		'+'
# define ATTR_MINUS		'-'
# define ATTR_HASH		'#'
# define ATTR_SPACE		' '

/*
** SPEC SYMBOLS
*/

# define SPEC_INTEGERS		"diouxXb"
# define SPEC_HEX			'x'
# define SPEC_HEX_UPPER		'X'
# define SPEC_OCTAL			'o'
# define SPEC_STRING		's'
# define SPEC_CHAR			'c'
# define SPEC_UNSIGNED		'u'
# define SPEC_PTR			'p'
# define SPEC_FLOAT			'f'
# define SPEC_PERCENT		'%'
# define SPEC_BIN			'b'

# define PADDING_CHAR			' '
# define PADDING_CHAR_ALT		'0'

# define FILL_TEMPLATE	"0000000000000000"
# define FILL_TEMPLATE_SIZE (16)

# define NULL_STRING_CONTENT		"(null)"
# define NULL_STRING_SIZE 			(6)
# define NULL_PTR_CONTENT			"(nil)"
# define NULL_PTR_SIZE				(5)

# define FLOAT_DEFAULT_PRECISION	(6)
# define FLOAT_PREFIX_NAN			"nan"
# define FLOAT_PREFIX_INFINITY		"inf"

# define OCTAL_PREFIX		"0"
# define HEX_PREFIX 		"0x"
# define HEX_PREFIX_UPPER 	"0X"
# define BIN_PREFIX 		"0b"

# define CHAR_NEGATIVE	"-"
# define CHAR_POSITIVE	"+"
# define CHAR_SPACE		" "

/*
** CONVERSION BUFFERS
** Using in some 'num convert to string' functions.
*/

# define BUFFER_CONVERSION_MAX			(32)
# define BUFFER_FLOAT_CONVERSION_MAX	(64)

typedef struct		s_arg
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	filling;
	unsigned int	padding;
	va_list			value;
	const char		*raw_input;
	char			*buffer;
	size_t			buff_len;
}					t_arg;

/*
** FORMATTING FLAGS
*/

enum	e_format_flags
{
	FLAG_FILL_ZERO = (1U << 0U),
	FLAG_LEFT = (1U << 1U),
	FLAG_PLUS = (1U << 2U),
	FLAG_SPACE = (1U << 3U),
	FLAG_HASH = (1U << 4U),
	FLAG_UPPERCASE = (1U << 5U),
	FLAG_CHAR = (1U << 6U),
	FLAG_SHORT = (1U << 7U),
	FLAG_LONG = (1U << 8U),
	FLAG_LONG_LONG = (1U << 9U),
	FLAG_PRECISION = (1U << 10U),
	FLAG_BASE_8 = (1U << 11U),
	FLAG_BASE_10 = (1U << 12U),
	FLAG_BASE_16 = (1U << 13U),
	FLAG_UNSIGNED = (1U << 14U),
	FLAG_NEGATIVE = (1U << 15U),
	FLAG_ERROR = (1U << 16U),
	FLAG_LONG_DOUBLE = (1U << 17U),
	FLAG_PTR = (1U << 18U),
	FLAG_NUMERIC = (1U << 19U),
	FLAG_FLOAT = (1U << 20U),
	FLAG_FILL_RIGHT = (1U << 21U),
	FLAG_INT_MAX = (1U << 22U),
	FLAG_SIZE_T = (1U << 23U),
	FLAG_BASE_2 = (1U << 24U),
	FLAG_OUTPUT_ERROR = (1U << 25U)
};

typedef int			(*t_format_func)(t_arg *arg);

/*
** NUMERICS
*/

unsigned int		atoi_min(const char **str);
size_t				itoa_min(unsigned long long nb, char *output);
int					specifier_is_integer(const char spec);
unsigned int		get_alt_number_symbols_length(unsigned int flags);

/*
** ARGS EVAL
*/

void				eval_arg_flags(t_arg *arg);
void				eval_arg_numerics(t_arg *arg);
void				eval_arg_length(t_arg *arg);
void				eval_arg_specifier(t_arg *arg, t_format_func *form_func);

/*
** INTEGER / FlAT MODULE
*/

size_t				itoa_raw(unsigned long long nb, char *output, t_arg *arg);
unsigned long long	n_to_unsigned(t_arg *arg);
unsigned long long	n_to_signed(t_arg *arg);
long double			convert_float(t_arg *arg);
size_t				ftoa(long double n, char *output, t_arg *arg);

/*
** FORMAT
*/

void				display_arg(t_arg *arg, const char *buff, size_t buff_len);
int					format_integer(t_arg *arg);
int					format_string(t_arg *arg);
int					format_char(t_arg *arg);
int					format_percent(t_arg *arg);
int					format_float(t_arg *arg);
int					format_pointer(t_arg *arg);

/*
** UTILS
*/

size_t				ut_strlen(const char *s);
size_t				ut_strnlen(const char *s, size_t max_len);
void				ut_strnrev(char *s, size_t size);
void				ut_strcat(char *dst, const char *src);
unsigned int		parse_wildchar(va_list va);

/*
** BUFFER
*/

void				buffer_fill(t_arg *arg, void *src, size_t len);
void				buffer_flush(t_arg *arg);

#endif
