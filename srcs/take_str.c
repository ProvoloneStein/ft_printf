/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:39:38 by pstein            #+#    #+#             */
/*   Updated: 2019/10/22 14:19:29 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			precision_str(char **str, t_flags *flags)
{
	if (flags->precision > -1)
		*str = ft_strsub_free(*str, 0, flags->precision);
}

static char		*wchar_str(wchar_t *w_str, t_flags *flags)
{
	char	*str;
	char	*temp;

	if (flags->precision == 0)
		return (ft_strdup(""));
	if ((str = wchar_c(*w_str)) == NULL)
		return (NULL);
	temp = str;
	if (!(*str))
		return (str);
	w_str++;
	while (*w_str && *temp)
	{
		if ((temp = wchar_c(*w_str)) == NULL)
			return (NULL);
		str = ft_strplus(str, temp, 1, 1);
		w_str++;
	}
	return (str);
}

char			*take_char(va_list *va, t_flags *flags)
{
	char		c;
	wchar_t		wc;

	if (flags->conv == 'C' || flags->type == l)
	{
		wc = (wchar_t)va_arg(*va, wint_t);
		if (!wc)
		{
			flags->null = 1;
			return (NULL);
		}
		return (wchar_c(wc));
	}
	else
	{
		c = (char)va_arg(*va, int);
		if (!c)
		{
			flags->null = 1;
			return (NULL);
		}
		return (make_char(c));
	}
}

char			*take_str(va_list *va, t_flags *flags)
{
	char		*str;
	wchar_t		*w_str;

	if (flags->conv == 'S' || flags->type == l)
	{
		w_str = (wchar_t *)va_arg(*va, wint_t *);
		if (!w_str)
			str = ft_strdup("(null)");
		else
			str = wchar_str(w_str, flags);
	}
	else
	{
		str = (char *)va_arg(*va, char *);
		if (!str)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(str);
	}
	if (str)
		precision_str(&str, flags);
	return (str);
}
