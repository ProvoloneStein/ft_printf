/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_str2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:08:40 by pstein            #+#    #+#             */
/*   Updated: 2019/10/22 14:20:33 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*wchar_c(wchar_t c)
{
	char	*str;

	if (c <= 255)
	{
		str = ft_strnew(1);
		str[0] = c;
		return (str);
	}
	else
		str = NULL;
	return (str);
}

char	*make_char(char c)
{
	char *str;

	str = ft_strnew(1);
	str[0] = c;
	return (str);
}
