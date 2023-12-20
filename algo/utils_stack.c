/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abd <mben-abd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:33:36 by mben-abd          #+#    #+#             */
/*   Updated: 2023/12/16 22:41:07 by mben-abd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap1.h"

t_stack_n	*find_last(t_stack_n *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool stack_sorted(t_stack_n *stack)
{
    if (!stack)
        return true;

    t_stack_n *current = stack;
    while (current)
    {
        if (current->nbr > current->next->nbr)
            return false;
        current = current->next;
    }

    return true;
}

int	ft_stack_size(t_stack_n *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack_n	*find_min(t_stack_n *stack)
{
	long		min;
	t_stack_n	*min_pointeur;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_pointeur = stack;
		}
		stack = stack->next;
	}
	return (min_pointeur);
}

t_stack_n	*find_max(t_stack_n *stack)
{
	long		max;
	t_stack_n	*max_pointeur;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_pointeur = stack;
		}
		stack = stack->next;
	}
	return (max_pointeur);
}
