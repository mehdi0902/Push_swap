/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:07 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/16 05:25:27 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void	turk(t_stack_n **a, t_stack_n **b)
{
	int	len_stack;

	len_stack = ft_stack_size(*a);
	if (len_stack-- > 3 && !stack_sorted(*a))
	{
		pa_pb(b, a, 1);
	}
	if (len_stack-- > 3 && !stack_sorted(*a))
	{
		pa_pb(b, b, 1);
	}
	//ft_putstr_fd("salllll1\n", 1);

	while (len_stack-- > 3 && !stack_sorted(*a))
	{
		//ft_putstr_fd("salllll2\n", 1);
		init_a_to_b(*a, *b);
		//ft_putstr_fd("salllll3\n", 1);
		mv_a_to_b(a, b);
		//ft_putstr_fd("salllll4\n", 1);
	}
	//ft_putstr_fd("salllll5\n", 1);

	if_three(a);
	ft_putstr_fd("salllll6\n", 1);
	while (*b)
	{
		ft_putstr_fd("salllll7\n", 1);
		init_b_to_a(*a, *b);
		ft_putstr_fd("salllll8\n", 1);
		mv_b_to_a(a, b);
		ft_putstr_fd("sallll9l\n", 1);
	}
	ft_putstr_fd("salllll10\n", 1);
	mid_index(*a);
	min_on_top(a);
	
}

void	rotate_a_and_b(t_stack_n **a, t_stack_n **b, t_stack_n *cheap)
{
	while (*b != cheap->target_n && *a != cheap)
		rr(a, b);
	mid_index(*a);
	mid_index(*b);
}

void	rev_rotate_a_and_b(t_stack_n **a, t_stack_n **b, t_stack_n *cheap)
{
	while (*b != cheap->target_n && *a != cheap)
		rrr(a, b);
	mid_index(*a);
	mid_index(*b);
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
