/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:06:11 by pstein            #+#    #+#             */
/*   Updated: 2019/12/25 12:47:56 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ok_sosi(char *str, char *str_plus, int i)
{
	i = i + 1;
	if (str[i] >= '5' && str[i] <= '9')
		str_plus = okruglenie_half(str, str_plus, i);
	else
		str = str_rewrite(str, i);
	if (str_plus)
		return (str_plus);
	return (str);
}

char	*okruglenie_lal(char *str, int i)
{
	int len;

	len = ft_strlen(str);
	return (str_revers(long_plus(str_revers(str),
					str_revers(ft_strplus(ft_strplus(zero_str(i - 1),
								"10", 1, 0), zero_str(len - i - 1), 1, 1)))));
}

char	*okruglenie(char *str, int precision)
{
	char	*str_plus;
	int		i;
	int		point;
	int		fix;

	point = 0;
	str_plus = NULL;
	i = check_after_stop(str);
	fix = i;
	if (str[i + 1] >= '5' && str[i + 1] <= '9' && precision == 0)
		return (okruglenie_lal(str, i));
	if (str[i + 1] <= '4' && precision == 0)
		return (str_rewrite(str, i));
	while (str[i] && precision > i - fix)
		i++;
	if (precision != i - fix)
	{
		str = ft_strplus(str, zero_str(precision - i + fix + 1), 1, 1);
		return (str);
	}
	return (ok_sosi(str, str_plus, i));
}

int		mod(int exp)
{
	if (exp < 0)
		return ((-1) * exp);
	return (exp);
}
