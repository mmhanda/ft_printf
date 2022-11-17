/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:18:36 by mhanda            #+#    #+#             */
/*   Updated: 2021/12/14 09:18:42 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int			len;
	long long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		len += ft_putchar('-');
	}
	if (nb < 10)
	{
		len += ft_putchar(nb + '0');
	}
	else
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	return (len);
}
