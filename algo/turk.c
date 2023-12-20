/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:07 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/20 13:38:41 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void turk(t_stack_n **a, t_stack_n **b)
{
    int len_stack;
    len_stack = ft_stack_size(*a);

    if (len_stack-- > 3 && !stack_sorted(*a))
    {
        //ft_putstr_fd("\nPile B : \n", 1);
        //stake(a);
		//ft_putstr_fd("\n--------\n", 1);
        //ft_putstr_fd("\nPile A : \n", 1);
        //stake(b);
		//ft_putstr_fd("\n--------\n", 1);
        if (*a != NULL) // Ajout de cette condition pour éviter d'appeler pb si la pile A est vide
            pb(a, b, 1);

        //ft_putstr_fd("\nPile B : \n", 1);
       // stake(a);
		//ft_putstr_fd("\n---7-----\n", 1);
        //ft_putstr_fd("\nPile A : \n", 1);
        //stake(b);
    }
	if (len_stack-- > 3 && !stack_sorted(*a))
	{
		//stake(a);
		//ft_putstr_fd("\n------1--\n", 1);
		//stake(b);
		pb(a, b, 1);

	}
	//stake(a);
	//ft_putstr_fd("\n--------\n", 1);
	//stake(b);
	//ft_putstr_fd("\n--------\n", 1);
	while (len_stack-- > 3 && !stack_sorted(*a))
	{	
		//stake(a);
		//ft_putstr_fd("\n--------\n", 1);
		//stake(b);
		init_a_to_b(*a, *b);
		mv_a_to_b(a, b);
		//stake(a);
		//ft_putstr_fd("\n--------\n", 1);
		//stake(b);

		//ft_putstr_fd("salllll4\n", 1);
	}
	////ft_putstr_fd("salllll5\n", 1);
	//ft_putstr_fd("oue15", 1);
		//stake(a);
		//ft_putstr_fd("\n--------\n", 1);
		//stake(b);
	if (len_stack == 3)
		if_three(b);
	//ft_putstr_fd("salllll6\n", 1);
	while (*b)
	{
		//ft_putstr_fd("salllll7\n", 1);
		init_b_to_a(*a, *b);
		//ft_putstr_fd("salllll8\n", 1);
		mv_b_to_a(a, b);
		//ft_putstr_fd("sallll9l\n", 1);
		
	}
	//ft_putstr_fd("salllll10\n", 1);
	mid_index(*a);
	min_on_top(a);
	
}

void	rotate_a_and_b(t_stack_n **a, t_stack_n **b, t_stack_n *cheap)
{
	//ft_putstr_fd("oue588", 1);
	while (*b != cheap->target_n && *a != cheap)
		rr(a, b, false);
	//ft_putstr_fd("oue588", 1);
	mid_index(*a);
	mid_index(*b);
}

void	rev_rotate_a_and_b(t_stack_n **a, t_stack_n **b, t_stack_n *cheap)
{
	//ft_putstr_fd("ou1", 1);
	while (*b != cheap->target_n && *a != cheap)
		rrr(a, b, false);
	//ft_putstr_fd("ou2", 1);
	mid_index(*a);
	mid_index(*b);
}

void	min_on_top(t_stack_n **a)
{
	//ft_putstr_fd("fdsfds", 1);
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		
		if (find_min(*a)->middle_up)
			ra(a, false);
		else
			rra(a, false);
	}
}
