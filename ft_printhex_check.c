/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:17:52 by mhanda            #+#    #+#             */
/*   Updated: 2021/12/14 11:21:01 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex_check(unsigned int nb, int base)
{
	int	len;

	len = 0;
	if (nb < 16)
	{
		if (nb < 10)
			len += ft_putchar(nb + 48);
		else
		{
			if (base == 1)
				len += ft_putchar(nb + 87);
			else
				len += ft_putchar(nb + 55);
		}
	}
	if (nb >= 16)
	{
			len += ft_printhex_check(nb / 16, base);
			len += ft_printhex_check(nb % 16, base);
	}
	return (len);
}
