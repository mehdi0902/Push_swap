/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_a_mv_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:29:39 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/20 13:36:49 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void	mv_a_to_b(t_stack_n **a, t_stack_n **b)
{
	/*t_stack_n	*cheapest_n;
	
	
	cheapest_n = cheapest_nbr(*a);
	//ft_putstr_fd("oue5zebu1", 1);
	if (cheapest_n->middle_up && cheapest_n->target_n->middle_up)
	{
		//ft_putstr_fd("oue5zebu", 1);
		rotate_a_and_b(a, b, cheapest_n);

	}
	else if (!(cheapest_n->middle_up) && !(cheapest_n->target_n->middle_up))
	{
		//ft_putstr_fd("oue5881", 1);
		rev_rotate_a_and_b(a, b, cheapest_n);
	}
	//ft_putstr_fd("oue588", 1);
	plan_to_push(a, cheapest_n, 'a');
	
	plan_to_push(b, cheapest_n->target_n, 'b');
	ft_putstr_fd("oue588", 1);
	pb(b, a, 1);*/

	

    t_stack_n *cheapest_n;

    cheapest_n = cheapest_nbr(*a);

    // Vérifiez si cheapest_n est NULL
    if (cheapest_n == NULL)
    {
        // Gestion du cas où cheapest_n est NULL
        // Peut-être une sortie anticipée ou une autre action appropriée
        return;
    }

    // Vérifiez si cheapest_n->target_n est NULL avant d'accéder à ses membres
    if (cheapest_n->target_n != NULL)
    {
        if (cheapest_n->middle_up && cheapest_n->target_n->middle_up)
        {
            rotate_a_and_b(a, b, cheapest_n);
        }
        else if (!(cheapest_n->middle_up) && !(cheapest_n->target_n->middle_up))
        {
            rev_rotate_a_and_b(a, b, cheapest_n);
        }
        plan_to_push(a, cheapest_n, 'a');
        plan_to_push(b, cheapest_n->target_n, 'b');
        //ft_putstr_fd("oue588", 1);
        pb(a, b, 1);
    }
    else
    {
        // Gestion du cas où cheapest_n->target_n est NULL
        // Peut-être une sortie anticipée ou une autre action appropriée
        return;
    }

}

void	mv_b_to_a(t_stack_n **a, t_stack_n **b)
{
	plan_to_push(a, (*b)->target_n, 'a');
	pa(a, b, 0);
}
