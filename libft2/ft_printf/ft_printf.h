/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:46:52 by mben-abd          #+#    #+#             */
/*   Updated: 2023/11/17 18:09:30 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_spec(int nb);
int		check_modulo(va_list yo, char c);
int		ft_printf(const char *str, ...);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_putnbr_unsigned(unsigned int n);
// int		print_hex_uppercase(unsigned int hexadecimal);
// int		print_hex_lowercase(unsigned int hexadecimal);
// int		ft_puthex_digit(unsigned int n, char *hex_chars, int *len);
int		hexadecimal(unsigned int num, char x_or_X);
int		dimitri(unsigned long long num);

#endif
