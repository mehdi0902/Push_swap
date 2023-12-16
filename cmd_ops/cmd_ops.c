/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 02:37:05 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/16 04:43:06 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void	sa_sb(t_stack_n **a, int i)
{
	int	tmp;

	tmp = (*a)->nbr;
	(*a)->nbr = (*a)->next->nbr;
	(*a)->next->nbr = tmp;
	if (i == 0)
		ft_putstr_fd("sa\n", 1);
	else if (i == 1)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_n **a, t_stack_n **b)
{
	sa_sb(a, 3);
	sa_sb(b, 3);
	ft_putstr_fd("ss\n", 1);
}

void	pa_pb(t_stack_n **a, t_stack_n **b, int i)
{
	t_stack_n	*tmp;

	if (*a == NULL)
		*a = *b;
	else
	{
		tmp = *a;
		*a = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
	if (i == 0)
		ft_putstr_fd("pa\n", 1);
	else if (i == 1)
		ft_putstr_fd("pb\n", 1);
}

void	ra_rb(t_stack_n **a, int i)
{
	t_stack_n	*tmp;
	t_stack_n	*last;

	tmp = (*a);
	*a = (*a)->next;
	last = (*a);
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = tmp;
	tmp->next = NULL;
	if (i == 0)
		ft_putstr_fd("ra\n", 1);
	else if (i == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_n **a, t_stack_n **b)
{
	ra_rb(a, 3);
	ra_rb(b, 3);
	ft_putstr_fd("rr\n", 1);
}
