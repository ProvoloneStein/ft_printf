/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:06:01 by pstein            #+#    #+#             */
/*   Updated: 2019/12/25 12:42:34 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*part_of_double_power(char *str, int pow, int num)
{
	int a;
	int nb;
	int i;

	i = 0;
	nb = 0;
	while (pow > 0 && pow--)
	{
		while (str[i])
		{
			a = (str[i] - '0') * num + nb;
			str[i] = a % 10 + '0';
			nb = a / 10;
			i++;
		}
		i = 0;
	}
	return (str);
}

char	*double_power(int pow)
{
	int		i;
	char	*str;

	i = 1;
	if (pow == 0)
	{
		str = (char *)malloc(sizeof(char) * (2));
		str[0] = '1';
		str[1] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (pow + 1));
	str[0] = '1';
	while (i < pow)
		str[i++] = '0';
	str[pow] = '\0';
	part_of_double_power(str, pow, 2);
	return (str);
}

char	*str_small_part(int pow)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (pow + 1));
	str[pow] = '\0';
	while (i < pow)
	{
		str[i] = '0';
		i++;
	}
	i = 0;
	str[0] = '1';
	part_of_double_power(str, pow, 5);
	return (str);
}

int		check_after_stop(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '.')
		i++;
	return (i);
}

char	*okruglenie_half(char *str, char *str_plus, int i)
{
	str = str_rewrite(str, i);
	str_plus = ft_strplus(zero_str(i - 1), "1", 1, 0);
	str_plus = str_revers(long_plus(str_revers(str),
				str_revers(str_plus)));
	return (str_plus);
}
