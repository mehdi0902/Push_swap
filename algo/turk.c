/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:07 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/15 21:41:09 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void	turk(t_stack_n **a, t_stack_n **b)
{
	int	len_stack;

	len_stack = ft_stack_size(*a);
	if (len_stack-- > 3 && !stack_sorted(*a))
	{
		pa_pb(b, a, 0);
	}
	if (len_stack-- > 3 && !stack_sorted(*a))
	{
		pa_pb(b, a, 0);
	}
	while (len_stack-- > 3 && !stack_sorted(*a))
	{
		init_a_to_b(a, b);
		mv_a_to_b(a, b);
	}
	if_three(a);
	while (*b)
	{
		init_b_to_a(a, b);
		mv_b_to_a(a, b);
	}
	mid_index(*a);
	min_on_top(a);
}

void	rotate_a_and_b(t_stack_n **a, t_stack_n **b, t_stack_n *cheap)
{
	while (*b != cheap->target_n && *a != cheap)
		rr(a, b);
	mid_index(a);
	mid_index(b);
}

void	rev_rotate_a_and_b(t_stack_n **a, t_stack_n **b, t_stack_n *cheap)
{
	while (*b != cheap->target_n && *a != cheap)
		rrr(a, b);
	mid_index(a);
	mid_index(b);
}

void	min_on_top(t_stack_n **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->middle_up)
			ra_rb(a, 0);
		else
			rra_rrb(a, 0);
	}
}
