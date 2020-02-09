/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:40:25 by pstein            #+#    #+#             */
/*   Updated: 2019/12/25 13:22:55 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** make precision
*/

void		precision_nb(char **str, t_flags *flags, int is_n)
{
	int		len;
	char	*new_s;

	if (flags->precision > 0)
	{
		len = flags->precision - ft_strlen(*str) + (**str == '-' ? 1 : 0);
		if (len > 0)
		{
			if (!(new_s = ft_strnew(len)))
				return ;
			ft_memset(new_s, '0', len);
			if (**str == '-')
				*str = ft_set1inside(new_s, *str, 1);
			else
				*str = ft_strplus(new_s, *str, 1, 1);
		}
		flags->zero = 0;
	}
	else if (!(flags->precision) && is_n)
	{
		free(*str);
		*str = ft_strdup("");
	}
}

/*
** bonus function! for apostrophe flag
*/

void		ap_maker(char **str, t_flags *flags)
{
	int				i;
	int				j;

	i = 1;
	j = ft_strlen(*str) - 1;
	if (flags->amp == 1)
	{
		while (j > 0)
		{
			if ((i % 3) == 0)
				*str = ft_inside(" ", *str, j);
			j--;
			i++;
		}
	}
}

/*
** octal, signed and unsigned nb
*/

char		*ft_o_nbrstr(va_list *va, t_flags *flags)
{
	char		*str;
	uintmax_t	n;

	n = pf_maxunb(va, flags);
	if (!(str = ft_uitoa_base(n, 8, 'a')))
		return (NULL);
	precision_nb(&str, flags, (n ? 0 : 1));
	if (str && flags->hash && str[0] != '0')
		str = ft_strplus("0", str, 0, 1);
	return (str);
}

char		*ft_nbrstr(va_list *va, t_flags *flags)
{
	intmax_t	n;
	char		*str;

	n = pf_maxnb(va, flags);
	if (!(str = ft_itoa_base(n, 10, 'a')))
		return (NULL);
	ap_maker(&str, flags);
	precision_nb(&str, flags, (n ? 0 : 1));
	if (flags->plus && str[0] != '-')
		str = ft_strplus("+", str, 0, 1);
	else if (flags->space && str[0] != '-')
		str = ft_strplus(" ", str, 0, 1);
	return (str);
}

char		*ft_unbrstr(va_list *va, t_flags *flags)
{
	uintmax_t	n;
	char		*str;

	n = pf_maxunb(va, flags);
	if (!(str = ft_uitoa_base(n, 10, 'a')))
		return (NULL);
	ap_maker(&str, flags);
	precision_nb(&str, flags, (n ? 0 : 1));
	return (str);
}
