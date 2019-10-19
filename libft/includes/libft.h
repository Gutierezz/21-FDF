/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:05:22 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/19 16:27:23 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <wchar.h>

# define ALLOC(Value) if (Value == NULL) return (-1);

# ifndef BUFF_SIZE
#  define BUFF_SIZE 10
# endif

# define HEX_STR "0123456789abcdef"
# define ABS(x) ((x) >= 0 ? (x) : -(x))

# define FLT_ABS(x) ((x < 0.0) ? (-x) : (x))

# define FT_EXP64_BIAS 1023
# define FT_EXP64_MASK	0x7FF
# define FT_SIGN64_OFFS	63
# define FT_MANT64_MASK	0xfffffffffffff
# define FT_SENULL64_MASK 0x000fffffffffffff
# define FT_MANT64_OFFS	52

# define FT_POS_INF	1.0f / 0.0f
# define FT_NEG_INF	-1.0f / 0.0f
# define FT_PNAN ft_nanval_double(0)
# define FT_NNAN ft_nanval_double(1)

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef union		u_double_un
{
	double			f;
	uint64_t		i;
}					t_double_un;

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, \
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char **s1, char **s2);
char				*ft_str_gapjoin(const char *s1, const char *s2, char gap);
char				*ft_str_gapjoin_free(char **s1, char **s2, char gap);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_string_array_del(char **arr);

int					ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
int					ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

size_t				ft_strwlen(const wchar_t *str);
int					get_wchar_size(wint_t c);
int					ft_putwchar_fd(wint_t c, int fd);
int					ft_putwchar(wint_t c);
int					ft_putwstr_fd(const wchar_t *str, size_t len, int fd);
int					ft_putwstr(const wchar_t *str, size_t len);
int					ft_put_rawstr_fd(const char *str, int fd);
void				ft_putspecialchar(unsigned char c, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_swap(int *a, int *b);
void				ft_bsort_params(char **arr, size_t size);
int					ft_countwords(char const *s, int c);
int					get_high_bit(int x);
int					get_next_line(const int fd, char **line);
int					get_next_line2(const int fd, char **line);
int					quick_select(int *arr, int start, int end, int k);

double				ft_floor(double x);
double				ft_round(double x);
double				ft_ceil(double x);
double				ft_modf(double x, double *iptr);

void				ft_round_double(double *nb, unsigned precision);
int					ft_getexp_dbl(double x);
int					ft_getsign_dbl(double x);
double				ft_nullsign_dbl(double x);
double				ft_nanval_double(int sign);
int					ft_isnan(double x);
int					ft_isinf(double x);
int					ft_iszero(double x);
int					ft_is_digit_string(const char *str);

size_t				ft_unblen_base(unsigned long long nb, unsigned int base);
size_t				ft_nblen(long long nb);

int					ft_atoi(const char *str);
int					ft_skip_prefix(const char *str, int base);
int					ft_is_base_digit(char c, int base);
int					ft_check_base(const char *str, int base);
int					ft_atoi_base(const char *str, int base);
long long			ft_atoll(const char *str);
double				ft_atof(const char *str);
char				*ft_ftoa(double nb, size_t prec, size_t *length, \
					int *exp_form);
char				*ft_itoa(int n);
char				*ft_lltoa(long long nb);
char				*ft_ulltoa_base(unsigned long long nb, unsigned int base);

#endif
