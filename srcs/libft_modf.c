/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_modf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:00:43 by pstein            #+#    #+#             */
/*   Updated: 2019/12/25 13:22:04 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** atoi for adress
*/

int				ft_atoi(char **str)
{
	int res;
	int is_neg;

	res = 0;
	is_neg = 0;
	while (**str == '\t' || **str == ' ' || **str == '\f'
			|| **str == '\n' || **str == '\r' || **str == '\v')
		(*str)++;
	if (**str == '-')
		is_neg = 1;
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str && **str >= '0' && **str <= '9')
	{
		res *= 10;
		res += **str - '0';
		(*str)++;
	}
	if (is_neg)
		res *= -1;
	return (res);
}

static void		free_all(char *s1, char *s2, int x, int y)
{
	if (x)
		free(s1);
	if (y)
		free(s2);
}

/*
**  strjoin free what we want
*/

char			*ft_strplus(char *s1, char *s2, int x, int y)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new_s == NULL)
		return (NULL);
	while (s1[i])
		new_s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_s[j++] = s2[i++];
	free_all(s1, s2, x, y);
	return (new_s);
}

/*
** s1 in х slot in s2! and free s1 and s2
*/

char			*ft_set1inside(char *s1, char *s2, unsigned int x)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new_s == NULL)
		return (NULL);
	while (s2[i] && i < x)
		new_s[j++] = s2[i++];
	i = 0;
	while (s1[i])
		new_s[j++] = s1[i++];
	i = x;
	while (s2[i])
		new_s[j++] = s2[i++];
	free_all(s1, s2, 1, 1);
	return (new_s);
}

char			*ft_strsub_free(char *s, unsigned int go, size_t l)
{
	char			*new_s;
	unsigned int	i;

	i = 0;
	new_s = ft_strnew(l);
	if (new_s == NULL)
		return (NULL);
	while (i < l)
	{
		new_s[i] = s[go];
		i++;
		go++;
	}
	free(s);
	return (new_s);
}
