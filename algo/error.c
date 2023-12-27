/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:52:12 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/26 23:59:54 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

int	if_duplicate(t_stack_n *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_sa_la(t_stack_n **stack)
{
	t_stack_n	*i;
	t_stack_n	*pointeur_s;

	if (!stack)
		return ;
	pointeur_s = *stack;
	while (pointeur_s)
	{
		i = pointeur_s->next;
		pointeur_s->nbr = 0;
		free(pointeur_s);
		pointeur_s = i;
	}
}

int	synthol(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0'
			&& str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

void	liberez_tout_mes_copains(t_stack_n **a)
{
	free_sa_la(a);
	ft_putstr_fd("Error", 1);
	exit(1);
}
