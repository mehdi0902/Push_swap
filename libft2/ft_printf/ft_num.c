/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:40:57 by mben-abd          #+#    #+#             */
/*   Updated: 2023/11/08 14:01:30 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_spec(int n)
{
	unsigned int	i;
	int				nb;

	nb = n;
	i = 1;
	if (n < 0 && n != -2147483648)
	{
		nb = -n;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	ft_putnbr_fd(n, 1);
	if (n == -2147483648)
		return (11);
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	digit;
	int		len;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (n < 10)
	{
		digit = '0' + n;
		write(1, &digit, 1);
		return (1);
	}
	else
	{
		len = 0;
		len += ft_putnbr_unsigned(n / 10);
		digit = '0' + (n % 10);
		write(1, &digit, 1);
		return (len + 1);
	}
}
