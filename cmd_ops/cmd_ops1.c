/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ops1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:57:57 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/26 23:54:00 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void	rra_rrb(t_stack_n **a, int i)
{
	t_stack_n	*last;
	t_stack_n	*secondlast;

	{
		last = *a;
		secondlast = NULL;
		if (*a == NULL || (*a)->next == NULL)
			return ;
		while (last->next != NULL)
		{
			secondlast = last;
			last = last->next;
		}
		last->next = *a;
		*a = last;
		secondlast->next = NULL;
		if (i == 0)
			ft_putstr_fd("rra\n", 1);
		else if (i == 1)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_stack_n **a, t_stack_n **b)
{
	rra_rrb(a, 3);
	rra_rrb(b, 3);
	ft_putstr_fd("rrr\n", 1);
}

void	stake(t_stack_n **a)
{
	t_stack_n	*tmp;

	tmp = *a;
	while (tmp)
	{
		ft_putnbr_fd(tmp->nbr, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
}

void	rr(t_stack_n **a, t_stack_n **b)
{
	ra_rb(a, 3);
	ra_rb(b, 3);
	ft_putstr_fd("rr\n", 1);
}
