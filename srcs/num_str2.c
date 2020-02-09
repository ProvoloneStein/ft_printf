/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_str2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:40:34 by pstein            #+#    #+#             */
/*   Updated: 2019/10/22 12:49:16 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_b_nbrstr(va_list *va, t_flags *flags)
{
	char		*str;
	uintmax_t	n;

	n = pf_maxunb(va, flags);
	if (!(str = ft_uitoa_base(n, 2, 'a')))
		return (NULL);
	precision_nb(&str, flags, (n ? 0 : 1));
	if (str && flags->hash && str[0] != '0')
		str = ft_strplus("0", str, 0, 1);
	return (str);
}

char	*ft_hstr(uintmax_t n, t_flags *flags)
{
	char *str;

	if (flags->conv == 'X')
		str = ft_uitoa_base(n, 16, 'A');
	else
		str = ft_uitoa_base(n, 16, 'a');
	if (!str)
		return (NULL);
	precision_nb(&str, flags, (n ? 0 : 1));
	if (flags->hash && !(n == 0 && flags->conv != 'p'))
		str = ft_strplus((flags->conv == 'X' ? "0X" : "0x"), str, 0, 1);
	return (str);
}

char	*ft_h_p_str(va_list *va, t_flags *flags)
{
	void	*str;
	long	n;

	str = va_arg(*va, void *);
	n = (unsigned long)str;
	flags->hash = 1;
	return (ft_hstr(n, flags));
}

char	*ft_h_nbrstr(va_list *va, t_flags *flags)
{
	uintmax_t	n;

	n = pf_maxunb(va, flags);
	return (ft_hstr(n, flags));
}
