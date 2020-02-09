/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:05:50 by pstein            #+#    #+#             */
/*   Updated: 2019/12/25 13:01:48 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*strchr_cpy(char *str, char s)
{
	int		index;
	char	*str_new;

	index = 0;
	while (str[index] != s)
		index++;
	str_new = (char *)malloc(sizeof(char) * (index + 1));
	str_new[index] = '\0';
	index = 0;
	while (str[index] != s)
	{
		str_new[index] = str[index];
		index++;
	}
	free(str);
	return (str_new);
}

char				*str_rewrite(char *str, unsigned long long i)
{
	int		j;
	char	*str_new;

	str_new = (char *)malloc(sizeof(char) * (i + 1));
	str_new[i] = '\0';
	j = 0;
	while (i - j > 0)
	{
		str_new[j] = str[j];
		j++;
	}
	free(str);
	return (str_new);
}

char				*str_revers(char *str)
{
	char	*str_new;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(str);
	str_new = (char *)malloc(sizeof(char) * (i + 1));
	str_new[i] = '\0';
	i--;
	while (i >= 0)
	{
		str_new[j] = str[i];
		j++;
		i--;
	}
	free(str);
	return (str_new);
}

char				*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	if (s1 && s2)
	{
		if ((str = (char *)malloc(sizeof(char) * ft_strlen(s1)
						+ ft_strlen(s2) + 1)) == NULL)
			return (NULL);
		i = 0;
		while (*s1)
			str[i++] = *s1++;
		while (*s2)
			str[i++] = *s2++;
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
