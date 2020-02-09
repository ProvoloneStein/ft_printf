/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:05:56 by pstein            #+#    #+#             */
/*   Updated: 2019/12/25 13:00:19 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*normalizer_part(char *str1, int i)
{
	char *str1_new;

	while (str1[i] == '0' && i < 19999)
		i++;
	str1_new = (char *)malloc(sizeof(char) * (20000 - i + 1));
	str1_new[20000 - i] = '\0';
	while (i <= 19999)
	{
		str1_new[19999 - i] = str1[i];
		i++;
	}
	return (str1_new);
}

char	*normalizer(char *str, char *str1)
{
	char			*str_new;
	char			*str1_new;
	long long int	i;
	long long int	len;
	long long int	j;

	j = 0;
	len = ft_strlen(str);
	i = len - 1;
	while (str[i] == '0' && i > 0)
		i--;
	str_new = (char *)malloc(sizeof(char) * (i + 2));
	str_new[i + 1] = '\0';
	while (i >= 0)
	{
		str_new[j] = str[i];
		i--;
		j++;
	}
	str1_new = normalizer_part(str1, 0);
	return (ft_strplus(ft_strplus(str_new, ".", 1, 0), str1_new, 1, 1));
}

char	*zero_str(long long int i)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = '0';
		i--;
	}
	return (str);
}

char	*ft_it(unsigned long long nb)
{
	char				*str;
	int					i;
	unsigned long long	pow;

	pow = nb;
	i = 1;
	while (pow /= 2)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i--] = '\0';
	while (nb)
	{
		str[i--] = nb % 2 + '0';
		nb /= 2;
	}
	return (str);
}

char	*long_plus(char *str, char *str_plus)
{
	int					i;
	int					j;
	int					nb;
	int					a;

	j = 0;
	i = 0;
	nb = 0;
	while (str[i] && str_plus[j])
	{
		if (str[i] == '.')
			j++;
		else
		{
			a = str[i] + str_plus[j] + nb - '0' - '0';
			str[i] = a % 10 + '0';
			nb = a / 10;
			j++;
		}
		i++;
	}
	free(str_plus);
	return (str);
}
