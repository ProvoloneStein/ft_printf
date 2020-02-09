/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:41:03 by pstein            #+#    #+#             */
/*   Updated: 2019/12/02 14:40:14 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_conv(char c)
{
	char	*str;

	str = CONVERSIONS;
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int			is_flag(char c)
{
	char	*str;

	str = FLAGS;
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void		null_flags(t_flags *flags)
{
	flags->type = none;
	flags->conv = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->null = 0;
	flags->precision = -1;
	flags->amp = 0;
}

char		*conv_checker(t_flags *flags, va_list *va)
{
	if (flags->conv == 'i' || flags->conv == 'd'
			|| flags->conv == 'D')
		return (ft_nbrstr(va, flags));
	else if (flags->conv == 'o' || flags->conv == 'O')
		return (ft_o_nbrstr(va, flags));
	else if (flags->conv == 'u' || flags->conv == 'U')
		return (ft_unbrstr(va, flags));
	else if (flags->conv == 'x' || flags->conv == 'X')
		return (ft_h_nbrstr(va, flags));
	else if (flags->conv == 'f' || flags->conv == 'F')
		return (str_dd(va, flags));
	else if (flags->conv == 'p')
		return (ft_h_p_str(va, flags));
	if (flags->conv == 's' || flags->conv == 'S')
		return (take_str(va, flags));
	else if (flags->conv == 'c' || flags->conv == 'C')
		return (take_char(va, flags));
	else if (flags->conv == 'b' || flags->conv == 'B')
		return (ft_b_nbrstr(va, flags));
	else
		return (make_char('%'));
}
