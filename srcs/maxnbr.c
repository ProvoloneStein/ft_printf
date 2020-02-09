/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:46:12 by pstein            #+#    #+#             */
/*   Updated: 2019/10/22 13:45:54 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	pf_maxnb(va_list *va, t_flags *flags)
{
	intmax_t n;

	if (flags->conv == 'D')
		n = (long)va_arg(*va, long);
	else if (flags->type == z)
		n = (size_t)va_arg(*va, size_t);
	else if (flags->type == j)
		n = (intmax_t)va_arg(*va, intmax_t);
	else if (flags->type == ll)
		n = (long long)va_arg(*va, long long);
	else if (flags->type == l)
		n = (long)va_arg(*va, long);
	else if (flags->type == h)
		n = (short)va_arg(*va, int);
	else if (flags->type == hh)
		n = (signed char)va_arg(*va, int);
	else
		n = (int)va_arg(*va, int);
	return (n);
}

uintmax_t	pf_maxunb(va_list *va, t_flags *flags)
{
	uintmax_t n;

	if (flags->conv == 'O' || flags->conv == 'U' || flags->conv == 'B')
		n = (unsigned long)va_arg(*va, unsigned long);
	else if (flags->type == z)
		n = (size_t)va_arg(*va, size_t);
	else if (flags->type == j)
		n = (uintmax_t)va_arg(*va, uintmax_t);
	else if (flags->type == ll)
		n = (unsigned long long)va_arg(*va, unsigned long long);
	else if (flags->type == l)
		n = (unsigned long)va_arg(*va, unsigned long);
	else if (flags->type == h)
		n = (unsigned short)va_arg(*va, unsigned int);
	else if (flags->type == hh)
		n = (unsigned char)va_arg(*va, unsigned int);
	else
		n = (unsigned int)va_arg(*va, int);
	return (n);
}
