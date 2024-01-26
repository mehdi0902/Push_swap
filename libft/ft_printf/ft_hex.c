/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:26:18 by mben-abd          #+#    #+#             */
/*   Updated: 2023/11/08 14:05:27 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexadecimal(unsigned int num, char x_or_X)
{
	char			string[25];
	char			*base_character;
	long long int	i;
	int				a;

	i = 0;
	a = 0;
	base_character = "0123456789abcdef";
	if (x_or_X == 'X')
		base_character = "0123456789ABCDEF";
	if (num == 0)
		return (ft_putchar('0'));
	while (num > 0)
	{
		string[i] = base_character[num % 16];
		num /= 16;
		i++;
		a++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(string[i]);
	}
	return (a);
}
