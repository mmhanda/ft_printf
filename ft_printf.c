/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanda <mhanda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 09:17:01 by mhanda            #+#    #+#             */
/*   Updated: 2021/12/14 15:24:13 by mhanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(const char str, va_list ap)
{
	int	len;

	len = 0;
	if (str == '%')
		len += ft_putchar('%');
	else if (str == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (str == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (str == 'u')
		len += ft_putnbr_usit(va_arg(ap, unsigned int));
	else if (str == 'x')
		len += ft_printhex_check(va_arg(ap, unsigned int), 1);
	else if (str == 'X')
		len += ft_printhex_check(va_arg(ap, unsigned int), 2);
	else if (str == 'd' || str == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (str == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_printhex(va_arg(ap, unsigned long int));
	}
	else
		len += ft_putchar(str);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = -1;
	len = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ' && str[i])
				i++;
			len += ft_checker(str[i], ap);
		}
		else
			len += ft_putchar(str[i]);
	}
	va_end(ap);
	return (len);
}
