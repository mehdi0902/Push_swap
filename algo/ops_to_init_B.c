/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_to_init_B.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:58:46 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/20 13:37:23 by mben-abd         ###   ########.fr       */
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

void	aim_for_b(t_stack_n *a, t_stack_n *b)
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
			if (pointeur_b->nbr < a->nbr && pointeur_b->nbr > best_comp)
			{
				best_comp = pointeur_b->nbr;
				node_target = pointeur_b;
			}
			pointeur_b = pointeur_b->next;
		}
		if (best_comp == LONG_MIN)
			a->target_n = find_max(b);
		else
			a->target_n = node_target;
		a = a->next;
		
	}
}

void	cost_a(t_stack_n *a, t_stack_n *b)
{
	/*int	size_a;
	int	size_b;

	size_a = ft_stack_size(a);
	size_b = ft_stack_size(b);
	//ft_putstr_fd("oue8", 1);
	while (a)
	{
		a->cmd_cost = a->index;
		if (!(a->middle_up))
			a->cmd_cost = size_a - (a->index);
		//ft_putstr_fd("oue8", 1);
		if (a->target_n->middle_up)
			a->cmd_cost += a->target_n->index;
		else
			a->cmd_cost += size_b - (a->target_n->index);
		//ft_putstr_fd("oue8", 1);
		
		a = a->next;
	}*/
    int size_a = ft_stack_size(a);
    int size_b = ft_stack_size(b);

    while (a != NULL)
    {
        a->cmd_cost = a->index;
        if (!(a->middle_up))
            a->cmd_cost = size_a - (a->index);

        if (a->target_n != NULL)
        {
            if (a->target_n->middle_up)
                a->cmd_cost += a->target_n->index;
            else
                a->cmd_cost += size_b - (a->target_n->index);
        }

        a = a->next;
    }


}

void	set_cheap(t_stack_n *stack)
{
	long		cheap_value;
	t_stack_n	*cheapest_n;

	if (!stack)
		return ;
	cheap_value = LONG_MAX;
	while (stack)
	{
		if (stack->cmd_cost < cheap_value)
		{
			cheap_value = stack->cmd_cost;
			cheapest_n = stack;
		}
		stack = stack->next;
	}
	cheapest_n->cheap = true;
}

void	init_a_to_b(t_stack_n *a, t_stack_n *b)
{

	mid_index(a);
	mid_index(b);
	aim_for_b(a, b);
	cost_a(a, b);
	set_cheap(a);
}
