/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstein <pstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:32:59 by pstein            #+#    #+#             */
/*   Updated: 2019/12/25 13:20:34 by pstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(intmax_t nb, intmax_t base, char lr)
{
	if (nb < 0)
		return (ft_strplus("-", ft_uitoa_base((nb * -1), base, lr),
					0, 1));
	else
		return (ft_uitoa_base(nb, base, lr));
}

char	*ft_uitoa_base(uintmax_t nb, intmax_t bs, char lr)
{
	uintmax_t	temp;
	int			power;
	char		*str;

	temp = nb;
	power = 1;
	while (temp /= bs)
		power++;
	if (!(str = ft_strnew(power)))
		return (NULL);
	while (power--)
	{
		if (nb % bs >= 10)
			str[power] = nb % bs - 10 + lr;
		else
			str[power] = nb % bs + '0';
		nb /= bs;
	}
	return (str);
}
