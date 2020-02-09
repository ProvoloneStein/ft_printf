/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:30:29 by pstein            #+#    #+#             */
/*   Updated: 2019/10/22 13:40:42 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdlib.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if ((mem = (char *)malloc(size)) == NULL)
		return (NULL);
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (s1[size])
		size++;
	if ((str = (char *)malloc(sizeof(*str) * (size + 1))) == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)ft_memalloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}
