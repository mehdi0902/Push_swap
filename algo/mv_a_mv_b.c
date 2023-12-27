/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_a_mv_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:29:39 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/26 23:56:41 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void	mv_a_to_b(t_stack_n **a, t_stack_n **b)
{
	t_stack_n	*cheapest_n;

	cheapest_n = cheapest_nbr(*a);
	if (cheapest_n == NULL)
	{
		return ;
	}
	if (cheapest_n->target_n != NULL)
	{
		if (cheapest_n->middle_up && cheapest_n->target_n->middle_up)
			rotate_a_and_b(a, b, cheapest_n);
		else if (!(cheapest_n->middle_up) && !(cheapest_n->target_n->middle_up))
			rev_rotate_a_and_b(a, b, cheapest_n);
		plan_to_push(a, cheapest_n, 'a');
		plan_to_push(b, cheapest_n->target_n, 'b');
		pb(a, b, 1);
	}
	else
		return ;
}

void	mv_b_to_a(t_stack_n **a, t_stack_n **b)
{
	plan_to_push(a, (*b)->target_n, 'a');
	pa(a, b, 0);
}
