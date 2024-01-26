/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:11:19 by mben-abd          #+#    #+#             */
/*   Updated: 2023/11/08 14:02:03 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_modulo(va_list yo, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(yo, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 's')
		return (ft_putstr(va_arg(yo, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_spec(va_arg(yo, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(yo, int)));
	else if (c == 'X' || c == 'x')
		return (hexadecimal(va_arg(yo, int), c));
	else if (c == 'p')
		return (dimitri(va_arg(yo, unsigned long long)));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	yo;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(yo, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len += check_modulo(yo, str[i]);
		}
		else
		{
			len += ft_putchar(str[i]);
		}
		i++;
	}
	return (len);
}

// int	main
