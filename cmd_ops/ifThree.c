/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifThree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:20:04 by mben-abd          #+#    #+#             */
/*   Updated: 2023/11/28 11:20:55 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

/*void	ifThree(t_stack_n **a)
{
	t_stack_n	*max_case;
	int			a;
	int			b;
	int			c;

	max_case = find_max(*a);
	if (max_case == *a)
		ra(a, 0);
	else if ((*a)->next == max_case)
		rra_rrb(a, 0);
	if ((*a)->nbr > (*a)->next->nbr)
		sa_sb(a, 0);
}*/
void	if_three(t_stack_n **s)
{
	int	a;
	int	b;
	int	c;

	a = (*s)->nbr;
	b = (*s)->next->nbr;
	c = (*s)->next->next->nbr;
	if (a > b && c > a)
		sa_sb(s, 0);
	else if (a > b && b > c)
	{
		sa_sb(s, 0);
		rra_rrb(s, 0);
	}
	else if (a > b && a > c && c > b)
		ra(s, 0);
	else if (a > b && b > c && c > a)
	{
		sa_sb(s, 0);
		ra(s, 0);
	}
	else if (a < b && b > c && a > c)
	{
		rra_rrb(s, 0);
	}
}
