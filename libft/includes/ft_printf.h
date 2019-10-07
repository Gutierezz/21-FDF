/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:01:53 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/22 17:03:10 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <locale.h>

# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_MAGENTA	"\x1b[35m"
# define ANSI_COLOR_CYAN	"\x1b[36m"
# define ANSI_COLOR_RESET	"\x1b[0m"

# define PF_PLUS  1
# define PF_MINUS 2
# define PF_SPACE 4
# define PF_HASH  8
# define PF_ZERO 16

# define PF_ABS(a) (a >= 0) ? (a) : (-a)
# define PF_MAX(a, b) ((a) > (b) ? (a) : (b))
# define PF_MIN(a, b) ((a) < (b) ? (a) : (b))

typedef enum		e_spec_size
{
	nosize = 0,
	h = 1,
	hh = 2,
	l = 3,
	ll = 4,
	L = 5,
	z = 6,
	j = 7,
	t = 8
}					t_spec_size;

typedef union		u_val
{
	intmax_t		i;
	uintmax_t		ui;
	double			f;
}					t_val;

typedef struct		s_ft_pf
{
	unsigned int	flags;
	size_t			f_width;
	int				prec;
	unsigned int	size;
	char			type;
	size_t			field_size;
	int				fd;
}					t_ft_pf;

typedef struct		s_pf_number
{
	t_val			*value;
	unsigned		sign;
	size_t			nb_len;
	unsigned int	base;
	char			*nb_str;
}					t_pf_number;

/*
** checker
**
** void decimal_checker();
** void unsigned_decimal_checker();
** void octal_checker();
** void hex_checker();
** void ptr_checker();
** void char_checker();
** void float_checker();
** void str_checker();
** void exp_check();
** void extra_check();
*/

/*
** struct_funcs
*/

t_ft_pf				*new_spec(const int fd);
t_pf_number			*new_number(t_val *value, size_t nb_len, unsigned int base);

/*
** isspec
*/

int					pf_is_flag(char c);
int					pf_is_size(char c);
int					pf_is_type(char c);
int					pf_is_unsigned(char c);
int					pf_is_float(char c);

/*
** parser
*/

int					parse_format(const char *format, size_t *i, va_list ap, \
					const int fd);
int					get_params(const char *format, size_t *i, t_ft_pf *spec, \
					va_list ap);
void				get_flag(char c, t_ft_pf *spec);
void				get_width_or_prec(const char *format, size_t *i, \
					t_ft_pf *spec, va_list ap);
void				get_size(const char *format, size_t *i, t_ft_pf *spec);

/*
** integer_helpers2
*/

int					compare_size_int(int new_index, int old_index);
int					right_align_with_zero_padding(t_ft_pf *s, \
					t_pf_number *num, size_t len);
unsigned int		get_int_base(char c);

/*
** ft_printf
*/

int					colored_print(const char *format, size_t *i);
int					ft_fprintf(const int fd, const char *format, ...);
int					ft_printf(const char *format, ...);
int					handle_type(t_ft_pf *spec, va_list ap);

/*
** string_char_helpers
*/
int					string_left_align(t_ft_pf *spec, size_t size, char *str);
int					printraw_left_align(t_ft_pf *spec, char *str);
int					wide_char_align(t_ft_pf *spec, int *err, int size, \
					wchar_t symb);
int					wide_str_left_align(t_ft_pf *spec, wchar_t *str, \
					size_t size);

/*
** string_char
*/

int					print_char(t_ft_pf *spec, va_list ap, int is_percent);
int					print_string(t_ft_pf *spec, va_list ap);
int					print_wide_char(t_ft_pf *spec, va_list ap, int is_percent);
int					print_wide_string(t_ft_pf *spec, va_list ap);
int					print_raw_string(t_ft_pf *spec, va_list ap);

/*
** print_signed_integer
*/

void				signed_cast(intmax_t *value, t_ft_pf *spec, va_list ap);
void				correct_size_signed(t_ft_pf *spec, t_pf_number *number);
int					handle_signed_integer(t_ft_pf *spec, va_list ap);
int					print_signed_integer(t_ft_pf *spec, t_pf_number *number);

/*
** print_unsigned_integer
*/

void				hash_correct(t_ft_pf *spec, t_pf_number *number);
void				unsigned_cast(uintmax_t *u_value, t_ft_pf *spec, \
					va_list ap);
void				correct_size_unsigned(t_ft_pf *spec, t_pf_number *number);
int					handle_unsigned_integer(t_ft_pf *spec, va_list ap);
int					print_unsigned_integer(t_ft_pf *spec, t_pf_number *number);

/*
** integer_helpers
*/

int					sign_and_prefix(t_ft_pf *spec, t_pf_number *number);
char				*fill_precision(t_ft_pf *spec, t_pf_number *number);
int					zero_with_zero_prec(t_ft_pf *spec, t_pf_number *number);
int					left_align(t_ft_pf *spec, t_pf_number *number);
int					right_align(t_ft_pf *spec, t_pf_number *number);

/*
** handle_float
*/

void				float_cast(t_val *value, t_ft_pf *spec, va_list ap);
void				correct_size_dbl(t_ft_pf *spec, t_pf_number *number, \
					int err);
int					print_floating_point(t_ft_pf *spec, t_pf_number *number);
int					handle_floating_point(t_ft_pf *spec, va_list ap);

/*
**float_helpers
*/

void				exp_str(t_ft_pf *spec, t_pf_number *number, int exp_form);
int					left_align_float(t_ft_pf *spec, t_pf_number *number);
int					right_align_float(t_ft_pf *spec, t_pf_number *number);

#endif
