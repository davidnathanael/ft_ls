/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:20:36 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/15 11:31:06 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <inttypes.h>
# include <string.h>

# define TRUE				1
# define FALSE				0

# define ERROR				-1
# define ERR_STRNEW			-2

# define NO_WIDTH			0
# define NO_PRECISION		-1

# define INT				'd'
# define I_INT				'i'
# define LONG				'D'
# define UNS_OCTAL			'o'
# define UNS_LONG_OCTAL		'O'
# define UNS_INT			'u'
# define UNS_LONG			'U'
# define UNS_HEXA			'x'
# define UNS_HEXA_MAJ		'X'
# define CHAR				'c'
# define WCHAR				'C'
# define STR				's'
# define WSTR				'S'
# define PTR				'p'
# define BINARY				'b'

# define F_SHARP			'#'
# define F_ZERO				'0'
# define F_MINUS			'-'
# define F_PLUS				'+'
# define F_SPACE			' '

# define NB_COLORS			10
# define ANSI_BOLD			"\x1b[1m"
# define ANSI_UNBOLD		"\x1b[22m"
# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"
# define ANSI_COLOR_CYAN	"\x1b[36m"
# define ANSI_COLOR_DEFAULT	"\x1b[39m"
# define ANSI_COLOR_RESET	"\x1b[0m"

typedef	unsigned char	t_bool;

typedef	int			t_width;
typedef	int			t_precision;
typedef	int			t_specifier;

typedef enum		e_type
{
	NO_TYPE,
	T_INT,
	T_LONG,
	T_LONG_LONG,
	T_SHORT,
	T_CHAR,
	T_INTMAX_T,
	T_UNS_INT,
	T_UNS_LONG,
	T_UNS_LONG_LONG,
	T_UNS_SHORT,
	T_UNS_CHAR,
	T_UINTMAX_T,
	T_SIZE_T,
	T_SSIZE_T,
	T_WINT_T,
	T_WCHAR_T,
	T_WCHAR_T_PTR,
	T_CHAR_PTR,
	T_VOID_PTR,
	T_NOT_VALID_TYPE,
}					t_type;

typedef enum		e_modifier
{
	NO_MODIFIER,
	M_L,
	M_LL,
	M_H,
	M_HH,
	M_J,
	M_Z,
}					t_modifier;

typedef struct		s_flags
{
	t_bool			sharp;
	t_bool			zero;
	t_bool			minus;
	t_bool			plus;
	t_bool			space;
}					t_flags;

typedef struct		s_options
{
	t_flags			*flags;
	t_width			width;
	t_precision		precision;
	t_modifier		modifier;
	t_specifier		specifier;
	t_type			type;
}					t_options;

int					ft_printf(const char *restrict format, ...);
int					ft_do_format(char *format, va_list ap);
char				*ft_check_color(char *str);

t_flags				*ft_get_flags(char *format);
t_bool				ft_has_flags(t_flags *flags);
t_bool				ft_is_flag(char c);
t_flags				*ft_check_flags(t_options *options, char *format);
wchar_t				*ft_apply_flags(t_options *options, wchar_t *arg,
					void *orig_arg);
wchar_t				*ft_apply_zero_flag_wstr(t_width width, wchar_t *arg);
char				*ft_apply_sharp_flag_hexa(t_specifier specifier,
					t_precision precision, t_flags *flags, char *arg);

t_bool				ft_skip(char *format);
t_bool				ft_is_modifier(char c);
int					ft_get_modifier(char *format);
t_options			*ft_apply_modifier(t_options *options);
t_type				ft_apply_l_modifier(t_specifier specifier);
t_type				ft_apply_ll_modifier(t_specifier specifier);
t_type				ft_apply_h_modifier(t_specifier specifier);
t_type				ft_apply_hh_modifier(t_specifier specifier);
t_type				ft_apply_j_modifier(t_specifier specifier);
t_type				ft_apply_z_modifier(t_specifier specifier);

int					ft_get_width(char *format, va_list ap);
char				*ft_apply_width(t_options *options, char *arg,
					void *orig_arg);
wchar_t				*ft_apply_width_wstr(t_options *options, wchar_t *arg,
					void *orig_arg);
char				*ft_get_spaces(t_width width);

int					ft_get_precision(char *format, va_list ap);
char				*ft_apply_precision(t_options *options, char *arg);
char				*ft_apply_precision_str(t_options *options, char *arg);
wchar_t				*ft_apply_precision_wstr(t_options *options, wchar_t *arg);
char				*ft_apply_precision_ptr(t_options *options, char *arg,
											unsigned long atoi);
char				*ft_get_zero(int len);
wchar_t				*ft_get_zero_wstr(int len);
char				*ft_prepend_zero(t_precision precision, char *arg);

char				*ft_get_signed_args(t_options *options, va_list ap);
char				*ft_get_unsigned_args(t_options *options, va_list ap);
wchar_t				*ft_get_ptr_arg(t_options *options, va_list ap);
wchar_t				*ft_get_wint_arg(t_options *options, va_list ap);

int					ft_proceed(t_options *options, wchar_t *arg);
int					ft_proceed_int(t_options *options, char *arg);
int					ft_proceed_char(t_options *options, char *arg);
int					ft_proceed_str(t_options *options, char *arg);
int					ft_proceed_wchar(t_options *options, wchar_t *arg);
int					ft_proceed_wstr(t_options *options, wchar_t *arg);
int					ft_proceed_ptr(t_options *options, char *arg);
int					ft_proceed_not_valid_type(t_options *options, char *arg);

#endif
