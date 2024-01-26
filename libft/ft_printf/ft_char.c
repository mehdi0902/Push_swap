/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:26:38 by mben-abd          #+#    #+#             */
/*   Updated: 2023/11/17 18:09:29 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	dimitri(unsigned long long num)
{
	char			string[25];
	char			*base_character;
	long long int	i;
	int				a;

	i = 0;
	a = 2;
	write(1, "0x", 2);
	base_character = "0123456789abcdef";
	if (num == 0)
		ft_putchar('0');
	if (num == 0)
		return (3);
	while (num > 0)
	{
		string[i++] = base_character[num % 16];
		num /= 16;
		a++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(string[i]);
	}
	return (a);
}
