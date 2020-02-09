/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:13:02 by pstein            #+#    #+#             */
/*   Updated: 2019/12/16 17:22:45 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  take precision and width. width has two flags IT BECAUSE WE NEED IT!!!!
*/

static int		flags_precisions(t_flags *flags, char **str, va_list *va)
{
	if (**str == '.')
	{
		(*str)++;
		flags->precision = 0;
		if (**str == '*')
		{
			flags->precision = va_arg(*va, int);
			(*str)++;
		}
		else
			flags->precision = ft_atoi(str);
		return (1);
	}
	else if (**str >= '1' && **str <= '9')
	{
		flags->width = ft_atoi(str);
		return (flags->flag_width = 1);
	}
	else if (**str == '*')
	{
		flags->width = va_arg(*va, int);
		(*str)++;
		return (flags->flag_width = 1);
	}
	return (0);
}

/*
** take all FLAGS!!!
*/

static int		flagset(t_flags *flags, char **str)
{
	if (**str == '#')
		flags->hash = 1;
	else if (**str == '0')
		flags->zero = 1;
	else if (**str == '-')
		flags->minus = 1;
	else if (**str == '+')
		flags->plus = 1;
	else if (**str == ' ')
		flags->space = 1;
	else if (**str == '\'')
		flags->amp = 1;
	else
		return (0);
	return (1);
}

/*
** take modificators
*/

static int		flags_size(t_flags *flags, char **str)
{
	if (**str == 'h' && *(*str + 1) == 'h' && flags->type < 1)
	{
		(*str)++;
		flags->type = hh;
	}
	else if (**str == 'h' && flags->type < 2)
		flags->type = h;
	else if (**str == 'z' && flags->type < 6)
		flags->type = z;
	else if (**str == 'j' && flags->type < 5)
		flags->type = j;
	else if (**str == 'l' && *(*str + 1) == 'l' && flags->type < 4)
	{
		flags->type = ll;
		(*str)++;
	}
	else if (**str == 'l' && flags->type < 3)
		flags->type = l;
	else if (**str == 'L' && flags->type < 7)
		flags->type = L;
	else
		return (0);
	return (1);
}

int				all_flags(t_flags *flags, char **str, va_list *va)
{
	null_flags(flags);
	while (**str && !is_conv(**str) && is_flag(**str))
	{
		if (flags_size(flags, str) || flagset(flags, str))
			(*str)++;
		else if (!flags_precisions(flags, str, va))
			(*str)++;
	}
	if (is_conv(**str))
		return (1);
	else if (**str)
		return (0);
	return (-1);
}
