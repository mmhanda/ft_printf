/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_usit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:18:28 by mhanda            #+#    #+#             */
/*   Updated: 2021/12/14 09:18:32 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_usit(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb < 10)
	{
		len += ft_putchar(nb + 48);
	}
	else
	{
		len += ft_putnbr_usit(nb / 10);
		len += ft_putnbr_usit(nb % 10);
	}
	return (len);
}
