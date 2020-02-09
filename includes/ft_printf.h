/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:54:08 by pstein            #+#    #+#             */
/*   Updated: 2019/12/25 13:28:24 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <ctype.h>
# include <stdlib.h>

# define CONVERSIONS	"sScCpdDioOuUxXfFbB%"
# define FLAGS			"#0-+ .'123456789hlLjz*"
# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define WHITE			"\x1b[37m"
# define RESET			"\x1b[0m"

typedef union				u_union
{
	long double				a;
	struct
	{
		unsigned long long	mant : 64;
		unsigned long long	exp : 15;
		unsigned long long	sign : 1;
	}						b_bit;
}							t_union;

typedef struct				s_flags
{
	char					conv;
	int						hash;
	int						zero;
	int						minus;
	int						plus;
	int						space;
	int						precision;
	int						width;
	int						amp;
	int						null;
	int						flag_width;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z,
		L
	}						type;

}							t_flags;

/*
** -----------------------ft_printf-----------------------------------
*/

int							ft_printf(const char *format, ...);
int							print_buff(char buff[4096], int *i, int fd);

/*
** -----------------------checker-----------------------------------
*/

int							is_conv(char c);
int							is_flag(char c);
void						null_flags(t_flags *flags);
char						*conv_checker(t_flags *flags, va_list *va);

/*
** -----------------------display-----------------------------------
*/

void						set_width(char **str, t_flags *flags);
int							lets_do_rock(va_list *va, char **str, int fd);

/*
** -----------------------flags-----------------------------------
*/

int							all_flags(t_flags *flags, char **str, va_list *va);

/*
** -----------------------ft_itoa_base-----------------------------------
*/

char						*ft_uitoa_base(uintmax_t nb, intmax_t bs, char lr);
char						*ft_itoa_base(intmax_t nb, intmax_t base, char lr);

/*
** -----------------------libf_f-----------------------------------
*/

void						*ft_memset(void *b, int c, size_t len);
size_t						ft_strlen(const char *s);
char						*ft_strnew(size_t size);
char						*ft_strdup(const char *s1);
void						*ft_memalloc(size_t size);

/*
** -----------------------libft_modf-----------------------------------
*/

int							ft_atoi(char **str);
char						*ft_strplus(char *s1, char *s2, int x, int y);
char						*ft_set1inside(char *s1, char *s2, unsigned int x);
char						*ft_strsub_free(char *s, unsigned int go, size_t l);

/*
** -----------------------libft_modf2-----------------------------------
*/

char						*ft_inside(char *s1, char *s2, unsigned int x);
int							ft_putstr_free(char *s);
int							ft_putstr_fd_free(char *s, int fd);
int							ft_putstr(char const *s);
void						ft_putstr_fd(char const *s, int fd);

/*
** -----------------------maxnbr-----------------------------------
*/

intmax_t					pf_maxnb(va_list *va, t_flags *flags);
uintmax_t					pf_maxunb(va_list *va, t_flags *flags);

/*
** -----------------------num_str-----------------------------------
*/

void						precision_nb(char **str, t_flags *flags, int is_n);
void						ap_maker(char **str, t_flags *flags);
char						*ft_o_nbrstr(va_list *va, t_flags *flags);
char						*ft_nbrstr(va_list *va, t_flags *flags);
char						*ft_unbrstr(va_list *va, t_flags *flags);

/*
** -----------------------num_str2-----------------------------------
*/

char						*ft_h_nbrstr(va_list *va, t_flags *flags);
char						*ft_h_p_str(va_list *va, t_flags *flags);
char						*ft_hstr(uintmax_t n, t_flags *flags);
char						*ft_b_nbrstr(va_list *va, t_flags *flags);

/*
** -----------------------ld_1.c-----------------------------------
*/

char						*strchr_cpy(char *str, char s);
char						*str_rewrite(char *str, unsigned long long i);
char						*str_revers(char *str);
char						*ft_strjoin(char *s1, char *s2);

/*
** -----------------------ld_2.c-----------------------------------
*/

char						*normalizer_part(char *str1, int i);
char						*normalizer(char *str, char *str1);
char						*zero_str(long long int i);
char						*ft_it(unsigned long long nb);
char						*long_plus(char *str, char *str_plus);

/*
** -----------------------ld_3.c-----------------------------------
*/

char						*part_of_double_power(char *str, int pow, int num);
char						*double_power(int pow);
char						*str_small_part(int pow);
int							check_after_stop(char *str);
char						*okruglenie_half(char *str, char *str_plus, int i);

/*
** -----------------------ld_4.c-----------------------------------
*/

char						*ok_sosi(char *str, char *str_plus, int i);
char						*okruglenie_lal(char *str, int i);
char						*okruglenie(char *str, int precision);
int							mod(int exp);

/*
** -----------------------long_double.c-----------------------------------
*/

char						*whole_part(char *str, long int exp, int precision);
char						*flags_check(char *str, t_flags *flags, int sign);
char						*str_dd(va_list *va, t_flags *fls);

/*
** -----------------------take_str-----------------------------------
*/

void						precision_str(char **str, t_flags *flags);
char						*take_char(va_list *va, t_flags *flags);
char						*take_str(va_list *va, t_flags *flags);

/*
** -----------------------take_str2-----------------------------------
*/

char						*wchar_c(wchar_t c);
char						*make_char(char c);

/*
** -----------------------colors-----------------------------------
*/

int							init_color(char **str, int color, int len);
int							color_check(char **str, char buff[4096], int *b_i);
int							ft_cmp(const char *s1, const char *s2, size_t n);

#endif
