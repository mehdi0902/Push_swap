/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_to_init_A.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:58:46 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/01 21:40:48 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void	mid_index(t_stack_n *stack)
{
	int	i;
	int	mid;

	i = 0;
	if (!stack)
		return ;
	mid = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= mid)
			stack->middle_up = true;
		else
			stack->middle_up = false;
		stack = stack->next;
		++i;
	}
}

void	aim_for_a(t_stack_n *a, t_stack_n *b)
{
	t_stack_n	*pointeur_b;
	t_stack_n	*node_target;
	long		best_comp;

	while (a)
	{
		best_comp = LONG_MIN;
		pointeur_b = b;
		while (pointeur_b)
		{
			if (pointeur_b->nbr > a->nbr && pointeur_b->nbr > best_comp)
			{
				best_comp = pointeur_b->nbr;
				node_target = pointeur_b;
			}
			pointeur_b = pointeur_b->next;
			if (best_comp == LONG_MIN)
				a->target_n = find_max(b);
			else
				a->target_n = node_target;
			a = a->next;
		}
	}
}

void	cost_a(t_stack_n *a, t_stack_n *b)
{
	int	size_a;
	int size_b;

	size_a = ft_stack_size(a);
	size_b = ft_stack_size(b);
	
	while(a)
	{
		a->cmd_cost = a->index;
		if (!(a->middle_up))
			a->cmd_cost = size_a - (a->index);
		if (a->target_n->middle_up)
			a->cmd_cost += a->target_n->index;
		else
			a->cmd_cost += size_b - (a->target_n->index);
		a = a->next;
	}
}




