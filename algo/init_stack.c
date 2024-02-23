/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:43:19 by mben-abd          #+#    #+#             */
/*   Updated: 2024/02/21 23:58:12 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

void	append(t_stack_n **stack, int n)
{
	t_stack_n	*node;
	t_stack_n	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_n));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
/*void	append(t_stack_n **top, int newnbr)
{
	t_stack_n	*newnode;
	t_stack_n	*last;

	newnode = malloc(sizeof(t_stack_n));
	if (!newnode)
		return ;
	last = *top;
	newnode->nbr = newnbr;
	newnode->next = NULL;
	if (!(*top))
	{
		*top = newnode;
		newnode->prev = NULL;
	}
	else
	{
		last = find_last(*top);
		last->next = newnode;
		newnode->prev = last;
	}
}*/

t_stack_n	*cheapest_nbr(t_stack_n *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	plan_to_push(t_stack_n **stack, t_stack_n *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->middle_up)
				ra_rb(stack, 0);
			else
				rra_rrb(stack, 0);
		}
		else if (stack_name == 'b')
		{
			if (top_node->middle_up)
				ra_rb(stack, 1);
			else
				rra_rrb(stack, 1);
		}
	}
}
/*void	plan_to_push(t_stack_n **stack, t_stack_n *top_n, char a_b)
{
	while (*stack != top_n)
	{
		if (a_b == 'a')
		{
			if (top_n->middle_up)
				ra_rb(stack, 0);
			else
				rra_rrb(stack, 0);
		}
		else if (a_b == 'b')
		{
			if (top_n->middle_up)
				ra_rb(stack, 1);
			else
				rra_rrb(stack, 1);
		}
		*stack = (*stack)->next;
	}

}*/

void	init_stack_a(t_stack_n **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (synthol(av[i]))
			liberez_tout_mes_copains(a);
		n = ft_atoi(av[i]);
		if (if_duplicate(*a, (int)n))
			liberez_tout_mes_copains(a);
		if (n > INT_MAX || n < INT_MIN)
			liberez_tout_mes_copains(a);
		append(a, (int)n);
		i++;
	}
}
