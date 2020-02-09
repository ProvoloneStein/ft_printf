/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:12:03 by pstein            #+#    #+#             */
/*   Updated: 2019/12/24 19:45:10 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** exterminatus for i and write buff
*/

int			print_buff(char buff[4096], int *i, int fd)
{
	int	ret;

	ret = *i;
	*i = 0;
	write(fd, buff, ret);
	return (ret);
}

static int	ft_count(char *str, va_list *va, int count)
{
	int		plus;
	char	b[4096];
	int		i;

	i = 0;
	while (*str)
	{
		if (i == 4095)
			count += print_buff(b, &i, 1);
		count += color_check(&str, b, &i);
		if (*str == '%')
		{
			if (!(*(++str)))
				return (count + print_buff(b, &i, 1));
			if ((plus = print_buff(b, &i, 1) + lets_do_rock(va, &str, 1)) == -1)
				return (-1);
			count += plus;
		}
		else
			b[i++] = *str;
		if (*str)
			str++;
	}
	return (count + print_buff(b, &i, 1));
}

/*
** we work with adresses of varibles!
*/

int			ft_printf(const char *format, ...)
{
	int		i;
	va_list	va;
	int		count;

	i = 0;
	count = 0;
	if (*format)
	{
		va_start(va, format);
		i = ft_count((char *)format, &va, count);
		va_end(va);
	}
	return (i);
}
