/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_doudle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:31:34 by gfreddie          #+#    #+#             */
/*   Updated: 2019/12/25 13:28:13 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	whole_part_half(char *str, char *str00, char *str01, long int exp)
{
	char	*s_p;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
		{
			if (exp >= 0)
			{
				s_p = double_power(exp);
				long_plus(str00, ft_strplus(s_p,
							zero_str(20000 - ft_strlen(s_p)), 1, 1));
			}
			else
			{
				s_p = str_small_part(mod(exp));
				long_plus(str01, ft_strplus(zero_str(20000 - ft_strlen(s_p)),
							s_p, 1, 1));
			}
		}
		i++;
		exp--;
	}
}

char		*whole_part(char *str, long int exp, int precision)
{
	char	*str00;
	char	*str01;
	char	*result;

	str00 = zero_str(20000);
	str01 = zero_str(20000);
	whole_part_half(str, str00, str01, exp);
	result = okruglenie(normalizer(str00, str01), precision);
	free(str00);
	free(str01);
	if (precision == 0)
		result = strchr_cpy(result, '.');
	if (result[0] == '.')
		result = ft_strjoin("0", result);
	free(str);
	return (result);
}

char		*flags_check(char *str, t_flags *flags, int sign)
{
	if (flags->plus && sign == 0)
	{
		str = ft_strjoin("+", str);
		flags->space = 0;
	}
	if (flags->space && sign == 0)
		str = ft_strjoin(" ", str);
	if (flags->hash && flags->precision == 0)
		str = ft_strjoin(str, ".");
	return (str);
}

char		*str_dd(va_list *va, t_flags *fls)
{
	t_union				bb;
	long double			b;
	unsigned long long	exp;

	if (fls->type == L)
		b = va_arg(*va, long double);
	else
		b = va_arg(*va, double);
	if (fls->precision == -1)
		fls->precision = 6;
	bb.a = b;
	exp = bb.b_bit.exp - 16383;
	if (bb.b_bit.sign != 0)
	{
		return (flags_check(ft_strplus("-", whole_part(ft_it(bb.b_bit.mant),
							exp, fls->precision), 0, 1), fls, bb.b_bit.sign));
	}
	return (flags_check(whole_part(ft_it(bb.b_bit.mant),
					exp, fls->precision), fls, bb.b_bit.sign));
}
