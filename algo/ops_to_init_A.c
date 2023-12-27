/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_to_init_A.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:03:19 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/22 20:23:53 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void	aim_for_a(t_stack_n *a, t_stack_n *b)
{
	t_stack_n	*pointeur_a;
	t_stack_n	*node_target;
	long		best_comp;

	while (b)
	{
		best_comp = LONG_MAX;
		pointeur_a = a;
		while (pointeur_a)
		{
			if (pointeur_a->nbr > b->nbr && pointeur_a->nbr < best_comp)
			{
				best_comp = pointeur_a->nbr;
				node_target = pointeur_a;
			}
			pointeur_a = pointeur_a->next;
		}
		if (best_comp == LONG_MAX)
			b->target_n = find_min(a);
		else
			b->target_n = node_target;
		b = b->next;
	}
}

void	init_b_to_a(t_stack_n *a, t_stack_n *b)
{
	mid_index(a);
	mid_index(b);
	aim_for_a(a, b);
}
